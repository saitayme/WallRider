// Fill out your copyright notice in the Description page of Project Settings.


#include "APlayerEntity.h"

#include "AShadeWalker.h"
#include "AToken.h"

// Sets default values
APlayerEntity::APlayerEntity()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// Override Member variables from AEntity
	Faction = EFactionType::Player;
	XLocation = 4;
	YLocation = 4;
}

void APlayerEntity::Interacted(AEntity* Other)
{
	// Super::Interacted(Other);

	if (Other != nullptr)
	{
		// if other == player then deal damage
		if (AShadeWalker* ShadeWalker = Cast<AShadeWalker>(Other))
		{
			// If the object is a ShadeWalker, call its Interact method
			ShadeWalker->Interact(this);
		}
		else if (AToken* Token = Cast<AToken>(Other))
		{
			// If the object is a Token, call its Interacted method
			Token->Interacted(this);
		}
	}
}

void APlayerEntity::Investigated(AEntity* Other)
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
