// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Event.h"
#include "TimedEvent.generated.h"

/**
 * 
 */
UCLASS()
class WALLRIDER_API UTimedEvent : public UEvent
{
	GENERATED_BODY()

public:

	UTimedEvent();

	UTimedEvent(FString QrCodeInfo);

	UPROPERTY(BlueprintReadWrite, Category="Stats")
	int DurationInRounds;

	UPROPERTY(BlueprintReadWrite, Category="Stats")
	int MaxAdvancePoints;

	

	virtual void InvokeEvent() override;

	UFUNCTION(BlueprintCallable, Category="Stats")
	void AdvanceEvent();

	UFUNCTION(BlueprintCallable, Category="Stats")
	void EndEvent();

	//EVENTS

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnEventWon);

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnEventFailed);
	
	UPROPERTY(BlueprintAssignable, EditAnywhere, Category="Session")
	FOnEventWon OnEventWon;
	
	UPROPERTY(BlueprintAssignable, EditAnywhere, Category="Session")
	FOnEventFailed OnEventFailed;

private:

	int CurrentAdvancePoints;

	int CurrentRoundCount;

	UFUNCTION(BlueprintCallable, Category="Turn", meta = (AllowPrivateAccess = "true"))
	void OnNextRound();
	
};
