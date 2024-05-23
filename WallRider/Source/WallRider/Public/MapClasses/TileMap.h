#pragma once

#include "CoreMinimal.h"
#include "Quadrant.h" // Include the Quadrant class
#include "Tile.h" // Include the Tile class
#include "Room.h" // Add this line at the top
#include "TileMap.generated.h"

UCLASS()
class WALLRIDER_API UTileMap : public UObject
{
    GENERATED_BODY()

public:
    UTileMap();
    virtual ~UTileMap();

    TArray<TArray<ATile>> GetCurrentHeatMap();
    void UpdateFields(TArray<ATile*> Tiles);
    void LockQuadrant(unsigned int QuadrantId);
    unsigned int GetShadewalkerQuadrant();
    ATile* GetEntityTile(AEntity* Entity);
    TArray<TArray<ATile>> DuplicateMap();
    void InitializeMap();
    bool IsBlockedByWall(int X, int Y);
    static ERoomType CharToRoomType(char C);
    void FindSourceTilePosition(AEntity* Entity, int& SourceX, int& SourceY);

private:
    TArray<TArray<ATile>> Tiles;
    TArray<UQuadrant*> Quadrants; // Collection of all quadrants
};
