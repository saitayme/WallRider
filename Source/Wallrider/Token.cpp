// Fill out your copyright notice in the Description page of Project Settings.


#include "Token.h"

#include "Entity/AEntity.h"


// Sets default values
AToken::AToken()
	: Faction(EFactionType::Token),
	  XLocation(0),
	  YLocation(0)
{
	// Set this actor to call Tick() every frame. Is turned off to improve performance
	PrimaryActorTick.bCanEverTick = false;
}

void AToken::Interacted(UObject* Other)
{
	if (const AEntity* OtherEntity = Cast<AEntity>(Other))
	{
		UE_LOG(LogTemp, Warning, TEXT("%s interacted with %s"), *OtherEntity->GetName(), *this->GetName());
	}	
}

void AToken::Investigated(UObject* Other)
{
	if (const AEntity* OtherEntity = Cast<AEntity>(Other))
	{
		UE_LOG(LogTemp, Warning, TEXT("%s investigated %s"), *OtherEntity->GetName(), *this->GetName());
	}
}

// Called when the game starts or when spawned
void AToken::BeginPlay()
{
	Super::BeginPlay();
}

