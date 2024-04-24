// Fill out your copyright notice in the Description page of Project Settings.


#include "AEntity.h"

#include "WallRider/GameMode/GameController.h"

// Sets default values
AEntity::AEntity()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void AEntity::BeginPlay()
{
	Super::BeginPlay();

	::AGameController* GameController = (AGameController*)GetWorld()->GetAuthGameMode();
	
	GameController->OnNextRound.AddDynamic(this, &AEntity::OnNextRound);
	GameController->OnNextTurn.AddDynamic(this, &AEntity::OnTurnStart);
}

void AEntity::Damage(const int value)
{
	CurrentHP -= value;
	Log("Ouch! I took damage!");
	
}

void AEntity::BuffAction(const TMap<EActionType, int>& Buff)
{
	
}

void AEntity::Interact(const FString& IInteractable)
{
	
}

void AEntity::Act(const UBaseAction* Action)
{
	
}

void AEntity::OnNextRound() 
{
	//Do stuff
}

void AEntity::OnTurnStart(AEntity* Entity)
{
	if (Entity == this)
	{
		
		Log("My Turn!");
	}
}

void AEntity::Log(const FString& s)
{
	UE_LOG(LogTemp, Warning, TEXT("%s - %s: %s"), *this->GetClass()->GetName(), *this->GetName(), *s);
}
