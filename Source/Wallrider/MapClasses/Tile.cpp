// In case Unreal deletes pointers we still want to use

#include "Tile.h"
#include "Room.h"  // Include Room.h here for full definition

#include "MapEnums.h"
#include "WallRider/Entity/AEntity.h"
#include "WallRider/Entity/FactionType.h"

// Parameters added as per instructions
UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Tile")
float CrumValue; // The crums are a float that need to be stored

UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Tile")
std::list<AEntity*> CurrentEntities; // Who is on that Tile

UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Tile")
std::map<FString, EBorderType> Borders; // What edges of the Tile are walk through and which are not

UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Tile")
URoom* room; // What room the tile is a part of

// Sets default values
ATile::ATile()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = false;
}


bool ATile::HasShadewalker() const {
    for (const AEntity* entity : CurrentEntities) {
        if (entity->Faction == EFactionType::ShadeWalker) { 
            return true;
        }
    }
    return false;
}

const TArray<AEntity*>& ATile::GetCurrentEntities() const {
    return CurrentEntities;
}

TMap<FString, EBorderType> ATile::GetBorders() const {
    return Borders;
}

EBorderType ATile::GetBorder(const FString& Direction) const {
    const EBorderType Copy = Borders[Direction];
    return Copy;
}

bool ATile::ContainsEntity(AEntity* entity) const {
    for (AEntity* currentEntity : CurrentEntities) {
        if (currentEntity == entity) {
            return true;
        }
    }
    return false;
}

void ATile::SetRoom(URoom* Room)
{
}

float ATile::GetCrumValue() const {
    return CrumValue;
}

// Called when the game starts or when spawned
void ATile::BeginPlay()
{
    Super::BeginPlay();
	
}

// Removed this duplicate definition of AddEntity
// void ATile::AddEntity(AEntity* entity) {
//     CurrentEntities.Add(entity);
// }

ATile* ATile::Clone() const {
    return nullptr;
}

FVector ATile::GetLocation() const {
    // Return the location of the tile
    return FVector(); // Placeholder
}

void ATile::SetOnFire(bool bIsOnFire) {
    // Implementation
}

//does what it says
void ATile::ChangeCrums(float delta) {
    CrumValue += delta;
}
//same here
void ATile::AddEntity(AEntity* entity) {
    CurrentEntities.Add(entity);
}
//if u dont get this ur stupid
void ATile::RemoveEntity(AEntity* entity) {
    CurrentEntities.RemoveSingle(entity);
}
//same here
void ATile::SetEdgeLocked(const FString& edge, bool locked) {
    Borders[edge] = locked ? EBorderType::Locked : EBorderType::None; // use BorderType::None ??? idk man
}
// Changing behavior
void ATile::ChangeBehaviour(BehaviourType NewBehaviour) {
    currentBehaviour = NewBehaviour;
}

bool ATile::HasEntity(AEntity* entity) const {
    return CurrentEntities.Contains(entity); // Ensure this matches the declaration in Tile.h
}

AEntity* ATile::GetEntity() const {
    if (CurrentEntities.Num() > 0) {
        return CurrentEntities[0];
    }
    return nullptr;
}