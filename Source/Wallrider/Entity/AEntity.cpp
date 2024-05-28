// Fill out your copyright notice in the Description page of Project Settings.


#include "AEntity.h"

#include "WallRider/GameMode/GameController.h"

// Sets default values
AEntity::AEntity()
	: MaxActionCount(2),
	  MaxHP(2),
	  Faction(EFactionType::Neutral),
	  XLocation(0),
	  YLocation(0),
	  xIndex(0),
	  yIndex(0),
	  CurrentActionCount(2),
	  CurrentHP(0)
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void AEntity::BeginPlay()
{
	Super::BeginPlay();

	::AGameController* GameController = static_cast<AGameController*>(GetWorld()->GetAuthGameMode());

	GameController->OnNextRound.AddDynamic(this, &AEntity::OnNextRound);
	GameController->OnNextTurn.AddDynamic(this, &AEntity::OnTurnStart);
}

void AEntity::Damage(const int Value)
{
	CurrentHP -= Value;
	Log("Ouch! I took damage!");
}

void AEntity::BuffAction(const TMap<EActionType, int>& Buff)
{
	// Iterate over the Buff map
	for (const auto& Pair : Buff)
	{
		// Depending on the ActionType, apply the buff
		switch (Pair.Key)
		{
		case EActionType::Interact:
			MaxActionCount += Pair.Value;
			break;
		case EActionType::Move:
			MaxHP += Pair.Value;
			break;
		case EActionType::Investigate:
			// Apply buff to Investigate action
			break;
		case EActionType::Pass:
			// Apply buff to Pass action
			break;
		case EActionType::Delay:
			// Apply buff to Delay action
			break;
		}
	}
}

void AEntity::Interact(IInteractable* Other)
{
    if (Other != nullptr)
    {
    	if (AEntity* OtherEntity = Cast<AEntity>(Other))
    	{
    		OtherEntity->Interacted(this);
    	}
    }
}

// Boris' approach of using the UInteractable interface
void AEntity::Interacted(UObject* Other)
{
	if (const AEntity* OtherEntity = Cast<AEntity>(Other))
	{
		UE_LOG(LogTemp, Warning, TEXT("%s interacted with %s"), *OtherEntity->GetName(), *this->GetName());
	}
}

// Boris' approach of using the UInteractable interface
EFactionType AEntity::Investigated(UObject* Other)
{
	if (const AEntity* OtherEntity = Cast<AEntity>(Other))
	{
		UE_LOG(LogTemp, Warning, TEXT("%s investigated %s"), *OtherEntity->GetName(), *this->GetName());
	}
	return EFactionType::Neutral;
}

/* Martin's approach of using the UInteractable interface
void AEntity::Interact(IInteractable* Other)
{
	if (Other != nullptr)
	{
		Other->Interacted(this);
	}
}*/

void AEntity::Move(int Direction)
{
	// Depending on the Direction, move the entity
	switch (Direction)
	{
	default:
		break;
	case 0: // North
		YLocation++;
		break;
	case 1: // East
		XLocation++;
		break;
	case 2: // South
		YLocation--;
		break;
	case 3: // West
		XLocation--;
		break;
	}
}

void AEntity::SetLocation(FVector NewLocation) {
    // Implementation
}

void AEntity::OnNextRound()
{
	// Reset the CurrentActionCount to MaxActionCount
	CurrentActionCount = MaxActionCount;

	// Set CurrentHP to MaxHP
	CurrentHP = MaxHP;

	// Log a message indicating the start of a new round
	FString roundStartMessage = FString::Printf(TEXT("A new round has started for %s"), *this->GetName());
	Log(roundStartMessage);
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
