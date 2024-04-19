#include "Tile.h"

#include "Room.h"

// Parameters added as per instructions
float CrumValue; // The crums are a float that need to be stored
std::list<Entity*> CurrentEntities; // Who is on that Tile
std::map<std::string, BorderType> Borders; // What edges of the Tile are walk through and which are not
Room* room; // What room the tile is a part of


Tile::Tile() : CrumValue(0), room(nullptr), currentBehaviour(BehaviourType::None)
{
}

Tile::~Tile()
{
}

//does what it says
void Tile::ChangeCrums(float delta) {
    CrumValue += delta;
}
//same here
void Tile::AddEntity(Entity* entity) {
    CurrentEntities.push_back(entity);
}
//if u dont get this ur stupid
void Tile::RemoveEntity(Entity* entity) {
    CurrentEntities.remove(entity);
}
//same here
void Tile::SetEdgeLocked(const std::string& edge, bool locked) {
    Borders[edge] = locked ? BorderType::Locked : BorderType::None; // use BorderType::None ??? idk man
}
// Changing behavior
void Tile::ChangeBehaviour(BehaviourType newBehaviour) {
    currentBehaviour = newBehaviour;
}

bool Tile::HasShadewalker() const {
    for (const auto& entity : CurrentEntities) {
        if (entity->IsShadewalker()) { 
            return true;
        }
    }
    return false;
}
