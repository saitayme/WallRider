// Fill out your copyright notice in the Description page of Project Settings.


#include "Room.h"
#include "Tile.h"  // Include Tile.h here for full definition

void URoom::Use(AEntity* Entity, const FString Instructions)
{
}

void URoom::Sabotage()
{
}

void URoom::MassSabotage()
{
}

void URoom::AddEntity(AEntity* Entity)
{
	Entities.Add(Entity->EntityId, Entity);
}

void URoom::RemoveEntity(FString EntityId)
{
	if (Entities.Contains(EntityId))
	{
		Entities.Remove(EntityId);
	}
}

void URoom::Interacted(UObject* Other)
{
}

void URoom::Investigated(UObject* Other)
{
}

ATile* URoom::GetRandomTile() {
    // Return a random tile from the room
    return nullptr; // Placeholder
}

TArray<ATile*> URoom::GetAllTiles() {
    // Return all tiles in the room
    return TArray<ATile*>(); // Placeholder
}
