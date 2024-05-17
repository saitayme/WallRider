// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerEntity.h"

#include "AShadeWalker.h"
#include "AToken.h"

// Sets default values
APlayerEntity::APlayerEntity()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

void APlayerEntity::Interacted(UObject* Other)
{
	// Super::Interacted(Other);

	if (Other != nullptr)
	{
		if (AShadeWalker* ShadeWalker = Cast<AShadeWalker>(Other))
		{
			// If the object is a ShadeWalker, call its Interact method
			ShadeWalker->Interact(this);
		}
		else if (AToken* Token = Cast<AToken>(Other))
		{
			// If the object is a Token, call its Interact method
			// TODO fix the below line
			// Token->Interact(this);
		}
	}
}

void APlayerEntity::Investigated(UObject* Other)
{
	Super::Investigated(Other);
}

// Called when the game starts or when spawned
void APlayerEntity::BeginPlay()
{
	Super::BeginPlay();
	
}

void APlayerEntity::Damage(const int Value)
{
	Super::Damage(Value);
	if (CurrentHP == 0)
	{
		Faction = EFactionType::Possessed;
		OnPossessed.Broadcast(this);
		Log("I'm possessed! >:)");
	}
}
