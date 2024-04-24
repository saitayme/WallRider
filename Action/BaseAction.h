// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ActionType.h"
#include "BaseAction.generated.h"
	
UCLASS()
class WALLRIDER_API UBaseAction : public UObject
{
	GENERATED_BODY()

public:
	
	UPROPERTY(BlueprintReadWrite, Category = "Stats")
	EActionType Action;

	UPROPERTY(BlueprintReadOnly, Category = "Stats")
	uint8 BuffValue;

	UFUNCTION(BlueprintCallable, Category="Action")
	virtual void Act(FString Instructions);

	UFUNCTION(BlueprintCallable, Category="Logging")
	void Log(const FString& s);
	
	
};
