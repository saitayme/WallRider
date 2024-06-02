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

	TArray<ATile*> GetCurrentTiles();
	
	void UpdateTileCrums(TArray<float> crumPattern);
	
	void LockQuadrant(uint16 QuadrantId);
	
	uint16 GetQuadrantIdWithShadeWalker();
	
	ATile* GetTileWithEntity(AEntity* entity);
	
	ATile* GetTile(int xLocation, int yLocation);
	
	static ATile* GetAdjacentTile(ATile* Tile, int Direction);
	
	void InitializeMap(TArray<ATile>);
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Setup")
	TArray<ATile*> Tiles;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Setup")
	int RowCount;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Setup")
	int ColumnCount;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
private:
	
	bool IsBlockedByWall(int x, int y);
	
	static ERoomType CharToRoomType(char c);
	
	int GetArrayIndex(const int RowIndex, const int ColumIndex) const;
	
	FIntVector GetXAndYFromArrayIndex(int32 ArrayIndex) const;
	
	UFUNCTION(BlueprintCallable, Category="Logging")
	void Log(const FString& S);
	
	void PopulateTileMap();
	
};
