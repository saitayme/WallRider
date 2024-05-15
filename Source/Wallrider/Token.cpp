// Fill out your copyright notice in the Description page of Project Settings.


#include "Token.h"


// Sets default values
AToken::AToken()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

void AToken::Interacted(UObject other)
{
	
}

void AToken::Investigated(UObject other)
{
	
}

// Called when the game starts or when spawned
void AToken::BeginPlay()
{
	Super::BeginPlay();
	
}

