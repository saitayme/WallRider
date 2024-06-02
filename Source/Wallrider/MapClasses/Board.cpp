// Fill out your copyright notice in the Description page of Project Settings.


#include "Board.h"

#include "Kismet/GameplayStatics.h"
// Sets default values
ABoard::ABoard()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

TArray<ATile*> ABoard::GetCurrentTiles()
{
	return Tiles;
}

ATile* ABoard::GetTile(int xLocation, int yLocation)
{
	return Tiles[GetArrayIndex(xLocation, yLocation)];
}

// Called when the game starts or when spawned
void ABoard::BeginPlay()
{
	Super::BeginPlay();
}

int ABoard::GetArrayIndex(const int RowIndex, const int ColumIndex) const
{
	if (RowIndex < RowCount && ColumIndex < ColumnCount) {
		return ( ColumIndex * ColumnCount) + RowIndex;
	} else {
		return 0;
	}
	
}

FIntVector ABoard::GetXAndYFromArrayIndex(int32 ArrayIndex) const
{
	const int32 gridY = ArrayIndex / ColumnCount;
	const int32 gridX = ArrayIndex % RowCount;
	return FIntVector(gridX, gridY, 0);
}

void ABoard::Log(const FString& S)
{
	UE_LOG(LogTemp, Warning, TEXT("%s: %s"), *this->GetName(), *S);
}

void ABoard::PopulateTileMap()
{
	TArray<AActor*> Actors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATile::StaticClass(), Actors);
	
	Tiles.Init(nullptr, Actors.Num());

	for (int i = 0; i < Actors.Num(); i++) {

		Tiles.Insert(static_cast<ATile*>(Actors[i]), GetArrayIndex(static_cast<ATile*>(Actors[i])->XLocation, static_cast<ATile*>(Actors[i])->YLocation));
	}
}

