#include "Quadrant.h"
#include "../MapClasses/Tile.h"

UQuadrant::UQuadrant(unsigned int QuadrantId, TArray<ATile*> Bounds) : QuadrantId(QuadrantId), Bounds(Bounds) {}

UQuadrant::~UQuadrant() {}

bool UQuadrant::CheckIfShadewalkerPresent() const {
    for (ATile* Tile : Bounds) {
        if (Tile->HasShadewalker()) { 
            return true;
        }
    }
    return false;
}

