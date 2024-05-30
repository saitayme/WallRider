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
	  BaseActionBuffs{
		  {EActionType::Interact, 0},
		  {EActionType::Move, 0},
		  {EActionType::Investigate, 0},
		  {EActionType::Pass, 0},
		  {EActionType::Delay, 0}
	  },
	  XIndex(0),
	  YIndex(0),
	  CurrentActionCount(0),
	  CurrentHP(0)
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	CurrentActionBuffs = BaseActionBuffs;
	CurrentActionCount = MaxActionCount;
	CurrentHP = MaxHP;
}

// Called when the game starts or when spawned
void AEntity::BeginPlay()
{
	Super::BeginPlay();

	/*commented out for testing purposes
	AGameController* GameController = static_cast<AGameController*>(GetWorld()->GetAuthGameMode());

	GameController->OnNextRound.AddDynamic(this, &AEntity::OnNextRound);
	GameController->OnNextTurn.AddDynamic(this, &AEntity::OnTurnStart);*/
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
		// Increment the corresponding action type in the ActionBuffs map
		CurrentActionBuffs[Pair.Key] += Pair.Value;
	}
}

void AEntity::Interact(const TScriptInterface<IInteractable> Other)
{
	if (Other != nullptr)
	{
		if (IInteractable* InteractableObject = Cast<IInteractable>(Other.GetObject()))
		{
			InteractableObject->Interacted(this);
		}
	}
}

void AEntity::Interacted(AEntity* Other)
{
	if (Other)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s interacted with %s"), *Other->GetName(), *this->GetName());
	}
}

void AEntity::Investigated(AEntity* Other)
{
	if (Other)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s investigated %s"), *Other->GetName(), *this->GetName());
	}
}

void AEntity::Move(const int Direction)
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


void AEntity::OnNextRound()
{
	CurrentActionCount = MaxActionCount;
	CurrentActionBuffs = BaseActionBuffs;

	// Log a message indicating the start of a new round
	const FString RoundStartMessage = FString::Printf(TEXT("A new round has started for %s"), *this->GetName());
	Log(RoundStartMessage);
}

void AEntity::OnTurnStart(AEntity* Entity)
{
	if (Entity == this)
	{
		Log("My Turn!");
	}
}

void AEntity::Log(const FString& S)
{
	UE_LOG(LogTemp, Warning, TEXT("%s - %s: %s"), *this->GetClass()->GetName(), *this->GetName(), *S);
}
