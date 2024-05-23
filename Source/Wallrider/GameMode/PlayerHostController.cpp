// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerHostController.h"


// Sets default values
APlayerHostController::APlayerHostController()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void APlayerHostController::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerHostController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

