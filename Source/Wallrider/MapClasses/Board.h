// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MapEnums.h"
#include "Tile.h"
#include "GameFramework/Actor.h"
#include "Wallrider/Entity/AEntity.h"
#include "Board.generated.h"

UCLASS()
class WALLRIDER_API ABoard : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABoard();

	TArray<ATile> GetCurrentTiles();

	void UpdateTileCrums(TArray<float> crumPattern);

	void LockQuadrant(uint16 QuadrantId);

	uint16 GetQuadrantIdWithShadeWalker();

	ATile* GetTileWithEntity(AEntity* entity);

	static ATile* GetTile(int xLocation, int yLocation);

	static ATile* GetAdjacentTile(ATile* Tile, int Direction);

	void InitializeMap(TArray<ATile>);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
private:
	
	bool IsBlockedByWall(int x, int y);
	
	static ERoomType CharToRoomType(char c);

	

/*
	 *std::vector<std::vector<Tile>> GetCurrentHeatMap();
    void UpdateFields(std::vector<Tile*> tiles);
    void LockQuadrant(unsigned int QuadrantId);
    unsigned int GetShadewalkerQuadrant();
    Tile* GetEntityTile(Entity* entity);
    std::vector<std::vector<Tile>> DuplicateMap();
    void InitializeMap();
    bool IsBlockedByWall(int x, int y);
    static RoomType CharToRoomType(char c);
    void FindSourceTilePosition(Entity* entity, int& sourceX, int& sourceY);

private:
    std::vector<std::vector<Tile>> Tiles;
    std::vector<Quadrant*> Quadrants; // Collection of all quadrants
	 */
	
};
