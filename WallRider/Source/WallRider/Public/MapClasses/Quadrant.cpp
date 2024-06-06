#include "Quadrant.h"
#include "../MapClasses/Tile.h"
#include "Misc/DefaultValueHelper.h"

UQuadrant::UQuadrant(unsigned int QuadrantId, TArray<ATile*> Bounds) : QuadrantId(QuadrantId), Bounds(Bounds) {}

UQuadrant::~UQuadrant() {}

void UQuadrant::LockQuadrant() {
    // Locking logic needs to be implemented based on Unreal Engine's methods
}

bool UQuadrant::CheckIfShadewalkerPresent() const {
    for (ATile* Tile : Bounds) {
        if (Tile->HasShadewalker()) { 
            return true;
        }
    }
    return false;
}

unsigned int UQuadrant::GetQuadrantId() const {
    return QuadrantId;
}
