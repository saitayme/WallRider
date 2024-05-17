// Fill out your copyright notice in the Description page of Project Settings.


#include "Token.h"


// Sets default values
AToken::AToken()
{
	// Set this actor to call Tick() every frame. Is turned off to improve performance
	PrimaryActorTick.bCanEverTick = false;

	
}

void AToken::Interacted(UObject* Other)
{
}

void AToken::Investigated(UObject* Other)
{
}

// Called when the game starts or when spawned
void AToken::BeginPlay()
{
	Super::BeginPlay();
	
}

