// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Quadrant.h" // Include the Quadrant class
#include "Tile.h" // Include the Tile class
#include "Room.h" // Add this line at the top
#include <vector> // Include support for std::vector

/**
 * 
 */
class WALLRIDER_API TileMap
{
public:
	TileMap();
	~TileMap();

    std::vector<std::vector<ATile*>> GetCurrentHeatMap();
    void UpdateFields(std::vector<ATile*> tiles);
    void LockQuadrant(unsigned int QuadrantId);
    unsigned int GetShadewalkerQuadrant();
    ATile* GetEntityTile(AEntity* entity);
    std::vector<std::vector<ATile*>> DuplicateMap();
    void InitializeMap();
    bool IsBlockedByWall(int x, int y);
    static ERoomType CharToRoomType(char c);
    void FindSourceTilePosition(AEntity* entity, int& sourceX, int& sourceY);

private:
    std::vector<std::vector<ATile*>> Tiles;
    std::vector<UQuadrant*> Quadrants; // Collection of all quadrants
};
