#include "Entity.h"
#include "MapClasses/Room.h" // Corrected path


Entity::Entity() : CurrentRoom(nullptr) {}

Entity::~Entity() {}

void Entity::SetCurrentRoom(Room* room) {
    CurrentRoom = room;
}

Room* Entity::GetCurrentRoom() const {
    return CurrentRoom;
}
