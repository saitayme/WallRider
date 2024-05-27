// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Card.h"
#include "Wallrider/UInteractable.h"
#include "Item.generated.h"

/**
 * 
 */
UCLASS()
class WALLRIDER_API UItem : public UCard, public IInteractable
{
	GENERATED_BODY()

public:

	UItem();

	AEntity* Owner;

	EFactionType SabotageFaction;

	virtual void Interacted(UObject* Other) override;
	virtual EFactionType Investigated(UObject* Other) override;

	void Sabotage(EFactionType Faction);

	//EVENTS

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FItemInteracted);
	FItemInteracted OnItemInteracted;

protected:

	void AssignItemToPlayer(AEntity* Player);
};
