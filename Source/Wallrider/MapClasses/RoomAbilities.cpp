// RoomAbilities.cpp

#include "RoomAbilities.h"
#include "Room.h"
#include "Tile.h" // Include this at the top of the file


TArray<URoom*> ARoomAbilities::AllRooms;

void ARoomAbilities::ActivateAbility(URoom* Room)
{
    switch (Room->Type)
    {
        case ERoomType::Laboratory:
            ActivateLaboratory(Room);
            break;
        case ERoomType::Control:
            ActivateControl(Room);
            break;
        case ERoomType::Hallway:
            ActivateHallway(Room);
            break;
        case ERoomType::Portal:
            ActivatePortal(Room);
            break;
        case ERoomType::QuantumBox:
            ActivateQuantumBox(Room);
            break;
        case ERoomType::Security:
            ActivateSecurity(Room);
            break;
        case ERoomType::Electrical:
            ActivateElectrical(Room);
            break;
        case ERoomType::Surgery:
            ActivateSurgery(Room);
            break;
        case ERoomType::Stim:
            ActivateStim(Room);
            break;
        case ERoomType::Breakroom:
            ActivateBreakroom(Room);
            break;
        case ERoomType::Kitchen:
            ActivateKitchen(Room);
            break;
        case ERoomType::Crematorium:
            ActivateCrematorium(Room);
            break;
        case ERoomType::Armory:
            ActivateArmory(Room);
            break;
        default:
            break;
    }
}

void ARoomAbilities::ActivateLaboratory(URoom* Room)
{
    // Future implementation
}

void ARoomAbilities::ActivateControl(URoom* Room)
{
    // Future implementation
}

void ARoomAbilities::ActivateHallway(URoom* Room) {
    // Implementation needed
}

void ARoomAbilities::ActivateQuantumBox(URoom* Room) {}
void ARoomAbilities::ActivateSecurity(URoom* Room) {}
void ARoomAbilities::ActivateElectrical(URoom* Room) {}
void ARoomAbilities::ActivateSurgery(URoom* Room) {}
void ARoomAbilities::ActivateStim(URoom* Room) {}
void ARoomAbilities::ActivateBreakroom(URoom* Room) {}
void ARoomAbilities::ActivateKitchen(URoom* Room) {}
void ARoomAbilities::ActivateArmory(URoom* Room) {}

void ARoomAbilities::ActivatePortal(URoom* Room)
{
    if (Room->GetEntities().Num() == 0) return; // No entities in the room to teleport

    // Get a random entity (assuming it's a player for simplicity)
    AEntity* Entity = Room->GetEntities()[0]; // Corrected access to the first entity

    // Find a random room that is not the current one
    URoom* TargetRoom = nullptr;
    do {
        int32 RandomIndex = FMath::RandRange(0, AllRooms.Num() - 1);
        TargetRoom = AllRooms[RandomIndex];
    } while (TargetRoom == Room || TargetRoom == nullptr);

    // Find a random tile within the target room
    ATile* TargetTile = TargetRoom->GetRandomTile();

    // Teleport the entity to the target tile
    Entity->SetLocation(TargetTile->GetLocation());
}

void ARoomAbilities::ActivateCrematorium(URoom* Room)
{
    for (ATile* Tile : Room->GetAllTiles())
    {
        Tile->SetOnFire(true); // Assuming SetOnFire is a method to handle fire logic
    }
    // Logic to reset fire after one turn should be handled by the game turn manager
}

/*void UGameManager::EndTurn() {
    for (URoom* Room : AllRooms) {
        if (Room->IsCrematorium()) {
            TArray<ATile*> Tiles = Room->GetAllTiles();
            for (ATile* Tile : Tiles) {
                Tile->SetOnFire(false);  // Reset fire state
            }
        }
    }
}
*/
