#include "Tile.h"
#include "../Entity/Entity.h"
#include "Room.h"

// Parameters added as per instructions
UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Tile", meta=(AllowPrivateAccess = "true"))
float CrumValue; // The crums are a float that need to be stored

UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Tile", meta=(AllowPrivateAccess = "true"))
TArray<AEntity*> CurrentEntities; // Who is on that Tile

UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Tile", meta=(AllowPrivateAccess = "true"))
TMap<FString, EBorderType> Borders; // What edges of the Tile are walk through and which are not

UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Tile", meta=(AllowPrivateAccess = "true"))
URoom* Room; // What room the tile is a part of

ATile::ATile() : CrumValue(0), Room(nullptr), CurrentBehaviour(EBehaviourType::None)
{
    PrimaryActorTick.bCanEverTick = false; // Disable ticking if not needed
}

ATile::~ATile()
{
    // Destructor implementation (can be empty if nothing to clean up)
}

//does what it says
void ATile::ChangeCrums(float Delta)
{
    CrumValue += Delta;
}

//same here
void ATile::AddEntity(AEntity* Entity)
{
    CurrentEntities.Add(Entity);
}

//if u dont get this ur stupid
void ATile::RemoveEntity(AEntity* Entity)
{
    CurrentEntities.RemoveSingle(Entity);
}

//same here
void ATile::SetEdgeLocked(const FString& Edge, bool Locked)
{
    Borders.Add(Edge, Locked ? EBorderType::Locked : EBorderType::None);
}

// Changing behavior
void ATile::ChangeBehaviour(EBehaviourType NewBehaviour)
{
    CurrentBehaviour = NewBehaviour;
}

bool ATile::HasShadewalker() const
{
    for (const AEntity* Entity : CurrentEntities)
    {
        if (Entity->IsShadewalker())
        {
            return true;
        }
    }
    return false;
}

AEntity* ATile::GetEntity() const {
    if (CurrentEntities.Num() > 0) {
        return CurrentEntities[0];
    }
    return nullptr;
}

bool ATile::HasEntity(AEntity* Entity) const {
    return CurrentEntities.Contains(Entity);
}
