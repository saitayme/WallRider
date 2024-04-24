#include "Room.h"
#include "../Entity/Entity.h"

void Room::Use(Entity* entity, const std::string& instruction) {
    // Implementation depends on the instruction and entity interaction
    if (ActOnUse) {
        ActOnUse(entity, instruction);
    }
}

void Room::AddEntity(Entity* entity) {
    Entities.push_back(entity);
}

void Room::RemoveEntity(Entity* entity) {
    Entities.erase(std::remove(Entities.begin(), Entities.end(), entity), Entities.end());
}

void Room::TriggerSabotage() {
    // Implementation depends on how sabotage affects the room or game state
}