// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Card.generated.h"

/**
 * 
 */
UCLASS()
class WALLRIDER_API UCard : public UObject
{
	GENERATED_BODY()

public:

	UCard(const FObjectInitializer& ObjectInitializer);

private:

	void InterpretQrCode(const FString qrCodeInfo);
};
