// Fill out your copyright notice in the Description page of Project Settings.


#include "Room.h"
#include "Tile.h"  // Include Tile.h here for full definition


URoom::URoom(ERoomType type) : Type(type) {}

URoom::URoom(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}

URoom::~URoom() {}



void URoom::AddEntity(AEntity* entity) {
    Entities.Add(entity);
}

void URoom::RemoveEntity(AEntity* entity) {
    Entities.Remove(entity);
}

void URoom::TriggerSabotage() {
    // Implementation depends on how sabotage affects the room or game state
}

void URoom::SetRoomType(ERoomType type) {
    Type = type;
}

void URoom::Sabotage()
{
}

void URoom::MassSabotage()
{
}

void URoom::Interacted(UObject* Other)
{
}

void URoom::Investigated(UObject* Other)
{
}

ATile* URoom::GetRandomTile() {
    if (Tiles
        .Num() == 0) return nullptr; // Check if there are no tiles
    int32 RandomIndex = FMath::RandRange(0, Tiles.Num() - 1);
    return Tiles[RandomIndex];
}

TArray<ATile*> URoom::GetAllTiles() {
    return Tiles;
}

TArray<AEntity*> URoom::GetEntities() const {
    // Implementation
    return Entities;  // Assuming Entities is a TArray<AEntity*>
}
