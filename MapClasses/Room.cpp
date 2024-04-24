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


