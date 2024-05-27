// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item.h"
#include "ChargedItem.generated.h"

/**
 * 
 */
UCLASS()
class WALLRIDER_API UChargedItem : public UItem
{
	GENERATED_BODY()
	
public:

	UChargedItem();
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Setup")
	int MaxCharges;

	virtual void Interacted(UObject* Other) override;
	virtual EFactionType Investigated(UObject* Other) override;

	//EVENTS

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FItemOutOfCharges);
	FItemOutOfCharges OnChargesEmpty;

	int CurrentCharges;

	
};
