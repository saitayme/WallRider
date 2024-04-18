// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Quadrant.h" // Include the Quadrant class
#include "Tile.h" // Include the Tile class
#include <vector> // Include support for std::vector

/**
 * 
 */
class WALLRIDER_API TileMap
{
public:
	TileMap();
	~TileMap();

    std::vector<std::vector<Tile>> GetCurrentHeatMap();
    void UpdateFields(std::vector<Tile*> tiles);
    void LockQuadrant(unsigned int QuadrantId);
    unsigned int GetShadewalkerQuadrant();
    Tile* GetEntityTile(Entity* entity);

private:
    std::vector<std::vector<Tile>> Tiles;
    std::vector<Quadrant*> Quadrants; // Collection of all quadrants
};
