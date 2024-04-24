#include "Quadrant.h"
#include "../MapClasses/Tile.h"

Quadrant::Quadrant(unsigned int QuadrantId, std::vector<Tile*> bounds) : QuadrantId(QuadrantId), bounds(bounds) {}

Quadrant::~Quadrant() {}



bool Quadrant::CheckIfShadewalkerPresent() {
    for (Tile* tile : bounds) {
        if (tile->HasShadewalker()) { 
            return true;
        }
    }
    return false;
}

