// Fill out your copyright notice in the Description page of Project Settings.


#include "AEntity.h"

#include "WallRider/GameMode/GameController.h"


// Sets default values
AEntity::AEntity()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AEntity::BeginPlay()
{
	Super::BeginPlay();

	AGameController* GameController = (AGameController*)GetWorld()->GetAuthGameMode();
	
	GameController->OnNextRound.AddDynamic(this, &AEntity::OnNextRound);
}

// Called every frame
void AEntity::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AEntity::OnNextRound() 
{
	//Do stuff
}

