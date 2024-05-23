// Fill out your copyright notice in the Description page of Project Settings.


#include "Room.h"

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
<<<<<<< HEAD
=======

void URoom::ActivateAbilityManually()
{
	ActivateAbility();
}

ATile* URoom::GetRandomTile()
{
    int32 RandomIndex = FMath::RandRange(0, Tiles.Num() - 1);
    return Tiles[RandomIndex]; // Assuming Tiles is an array of tile pointers
}

TArray<ATile*> URoom::GetAllTiles()
{
    return Tiles; // Assuming Tiles is an array of tile pointers
}
>>>>>>> JulsDev
