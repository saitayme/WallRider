// Fill out your copyright notice in the Description page of Project Settings.


#include "TimedEvent.h"
#include "Wallrider/GameMode/GameController.h"

UTimedEvent::UTimedEvent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    // Constructor implementation
}

UTimedEvent::UTimedEvent(FString QrCodeInfo)
{

	AGameController* GameController = static_cast<AGameController*>(UObject::GetWorld()->GetAuthGameMode());

	GameController->OnNextRound.AddDynamic(this, &UTimedEvent::OnNextRound);

}

void UTimedEvent::InvokeEvent()
{
	Super::InvokeEvent();
}

void UTimedEvent::AdvanceEvent()
{
	CurrentAdvancePoints++;
}

void UTimedEvent::EndEvent()
{
	if (CurrentAdvancePoints >= MaxAdvancePoints) {
	
		OnEventWon.Broadcast();

	} else {

		OnEventFailed.Broadcast();
	
	}

	CurrentAdvancePoints = 0;
}

void UTimedEvent::OnNextRound()
{
	CurrentRoundCount++;

	if (CurrentRoundCount == DurationInRounds) {
		
		EndEvent();

	}
}
