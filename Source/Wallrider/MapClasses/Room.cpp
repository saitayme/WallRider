// Fill out your copyright notice in the Description page of Project Settings.


#include "Room.h"

void URoom::Interacted(AEntity* Other)
{
	if (SabotageFaction != EFactionType::Neutral) {
		
		Other->Damage(1);
		SabotageFaction = EFactionType::Neutral;
	}
	//Activate Room ability here
}

EFactionType URoom::Investigated()
{
	return SabotageFaction;
}

void URoom::Sabotage(EFactionType Faction)
{
	SabotageFaction = Faction;
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
