// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseAction.h"
#include "Move.generated.h"

UCLASS()
class WALLRIDER_API UMove : public UBaseAction
{
	GENERATED_BODY()

public:
	
	virtual void Act(FString Instructions) override;
};
