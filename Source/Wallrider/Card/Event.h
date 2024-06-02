// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Card.h"
#include "Event.generated.h"

/**
 * 
 */
UCLASS()
class WALLRIDER_API UEvent : public UCard
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable)
	virtual void InvokeEvent();

};
