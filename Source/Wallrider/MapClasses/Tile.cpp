// In case Unreal deletes pointers we still want to use

#include "Tile.h"

#include "MapEnums.h"
#include "WallRider/Entity/AEntity.h"
#include "WallRider/Entity/EFactionType.h"


// Sets default values
ATile::ATile()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

void ATile::SetEdgeLocked(EEdgeType Edge, bool Locked)
{
	Borders[Edge] = Locked ? EBorderType::Locked : EBorderType::None; // use BorderType::None ??? idk man
}

bool ATile::HasShadewalker()
{
	for (const AEntity* entity : CurrentEntities) {
		if (entity->Faction == EFactionType::ShadeWalker) { 
			return true;
		}
	}
	return false;
}

TArray<AEntity*> ATile::GetCurrentEntities()
{
	return CurrentEntities;
}

TMap<EEdgeType, EBorderType> ATile::GetBorders()
{
	const TMap<EEdgeType, EBorderType> Copy = Borders;
	return Copy;
}

EBorderType ATile::GetBorder(const EEdgeType Direction)
{
	const EBorderType Copy = Borders[Direction];
	return Copy;
}

void ATile::ChangeCrumValue(float delta)
{
	CrumValue += delta;
}

void ATile::SetRoom(URoom* Room)
{
}

float ATile::GetCrumValue()
{
	return CrumValue;
}

// Called when the game starts or when spawned
void ATile::BeginPlay()
{
	Super::BeginPlay();
	
}

void ATile::AddEntity(AEntity* Entity)
{
	CurrentEntities.Add(Entity);
}

void ATile::RemoveEntity(AEntity* Entity)
{
	CurrentEntities.Remove(Entity);
}

ATile* ATile::Clone()
{
	return nullptr;
}

