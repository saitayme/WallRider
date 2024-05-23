// RoomAbilities.cpp

#include "RoomAbilities.h"
#include "Room.h"

void RoomAbilities::ActivateAbility(URoom* Room)
{
    switch (Room->RoomType)
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

void RoomAbilities::ActivateLaboratory(URoom* Room)
{
    // Future implementation
}

void RoomAbilities::ActivateControl(URoom* Room)
{
    // Future implementation
}


void RoomAbilities::ActivateQuantumBox(URoom* Room) {}
void RoomAbilities::ActivateSecurity(URoom* Room) {}
void RoomAbilities::ActivateElectrical(URoom* Room) {}
void RoomAbilities::ActivateSurgery(URoom* Room) {}
void RoomAbilities::ActivateStim(URoom* Room) {}
void RoomAbilities::ActivateBreakroom(URoom* Room) {}
void RoomAbilities::ActivateKitchen(URoom* Room) {}
void RoomAbilities::ActivateArmory(URoom* Room) {}

void RoomAbilities::ActivatePortal(URoom* Room)
{
    if (Room->Entities.Num() == 0) return; // No entities in the room to teleport

    // Get a random entity (assuming it's a player for simplicity)
    AEntity* Entity = Room->Entities.Array()[0]; // Get the first entity

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

void RoomAbilities::ActivateCrematorium(URoom* Room)
{
    for (ATile* Tile : Room->GetAllTiles())
    {
        Tile->SetOnFire(true); // Assuming SetOnFire is a method to handle fire logic
    }
    // Logic to reset fire after one turn should be handled by the game turn manager
}

