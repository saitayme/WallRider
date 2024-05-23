// Fill out your copyright notice in the Description page of Project Settings.


#include "AToken.h"

#include "AEntity.h"
#include "PlayerEntity.h"
#include "Wallrider/MapClasses/Room.h"

// Initialize the list of possible items
const TArray<FString> AToken::ItemList = {"Flare", "Sound", "Fire"};

// Sets default values
AToken::AToken()
	: Faction(EFactionType::Token),
	  XLocation(0),
	  YLocation(0)
{
	// Set this actor to call Tick() every frame. Is turned off to improve performance
	PrimaryActorTick.bCanEverTick = false;
	
	// Generate a random item
	const int32 Index = FMath::RandRange(0, ItemList.Num() - 1);
	Item = ItemList[Index];
}

void AToken::Interacted(AEntity* Other)
{
	// Use the item
	Use(Cast<APlayerEntity>(Other));
	// Then remove the token from the game
	this->Destroy();

	if (const URoom* Room = Cast<URoom>(Other))
	{
		// Define what should happen when a token interacts with a room
		// For example, log a message
		UE_LOG(LogTemp, Warning, TEXT("%s interacted with %s"), *this->GetName(), *Room->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("%s interacted with %s"), *Other->GetName(), *this->GetName());
	}
}

void AToken::Investigated(AEntity* Other)
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

void AToken::Use(const APlayerEntity* PlayerEntity) const
{
	UE_LOG(LogTemp, Warning, TEXT("%s used at location (%d, %d)"), *Item, PlayerEntity->XLocation, PlayerEntity->YLocation);
}

