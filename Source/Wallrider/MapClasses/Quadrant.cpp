// Fill out your copyright notice in the Description page of Project Settings.

#include "Quadrant.h"
#include "Tile.h"  // Assuming Tile.h is in the same directory as Quadrant.cpp


UQuadrant::UQuadrant() {
    // Constructor implementation
}

void UQuadrant::LockQuadrant() {
    // Locking logic implementation
}

unsigned int UQuadrant::GetQuadrantId() const {
    return QuadrantId;
}

bool UQuadrant::CheckIfShadewalkerPresent() const {
    for (ATile* tile : bounds) {
        if (tile->HasShadewalker()) { 
            return true;
        }
    }
    return false;
}
