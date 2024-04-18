// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tile.h" // Include the Tile class
#include <vector> // Include support for std::vector

class WALLRIDER_API Quadrant
{
public:
    Quadrant(unsigned int QuadrantId, std::vector<Tile*> bounds);
    ~Quadrant();

    void LockQuadrant();
    bool CheckIfShadewalkerPresent();

private:
    unsigned int QuadrantId;
    std::vector<Tile*> bounds;
};
