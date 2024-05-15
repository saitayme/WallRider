// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerEntity.h"
	
// Sets default values
APlayerEntity::APlayerEntity()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

void APlayerEntity::Interacted(UObject other)
{
	
}

void APlayerEntity::Investigated(UObject other)
{
	
}

// Called when the game starts or when spawned
void APlayerEntity::BeginPlay()
{
	Super::BeginPlay();
	
}

void APlayerEntity::Damage(const int value)
{
	Super::Damage(value);
	if (CurrentHP == 0)
	{
		Faction = EFactionType::Possessed;
		OnPossessed.Broadcast(this);
		Log("I'm possessed! >:)");
	}
}

//TODO: Implement this