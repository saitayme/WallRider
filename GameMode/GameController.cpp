// Fill out your copyright notice in the Description page of Project Settings.


#include "GameController.h"

#include "Kismet/GameplayStatics.h"


// Sets default values
AGameController::AGameController()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AGameController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Wallrider GameMode started running sis"));
	
	SetMapRef();
	SetPlayerHostControllerRef();
	SpawnEntities();
	SetPlayerHostCamera();
}

void AGameController::SetEntitiesRef(const int playerCount)
{
	for (int i = 0; i < playerCount; i++)
	{
		const FVector Location = FVector(0.0f, 0.0f, 0.0f);
		const FRotator Rotation = FRotator(0.0f, 0.0f, 0.0f);
		AEntity* Entity = (AEntity*)GetWorld()->SpawnActor<AEntity>(AEntity::StaticClass(), Location, Rotation);
		Entities.Add(Entity);
	}
}

void AGameController::SetPlayerHostControllerRef()
{
	if (PlayerHostControllerRef == nullptr)
	{
		PlayerHostControllerRef = (APlayerHostController*)GetWorld()->GetFirstPlayerController();
	}
}

void AGameController::SetMapRef()
{
	if (Board == nullptr)
	{
		TArray<AActor*> Actors;
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), ABoard::StaticClass(), Actors);

		for (int i = 0; i < Actors.Num(); i++)
		{
			Board = (ABoard*)Actors[i];
		}
	}
}

void AGameController::SpawnEntities()
{
	//TODO: Spawn Entities in correct map location
	/*
	for (AEntity* entity : Entities)
	{
		switch (entity->FactionType) 
		{

		case FactionType::Shadewalker:

		break;

		case FactionType::Player:

		break;
		
		default: ;
			//TODO: Also spawn the tokens!
		}
	}
	*/
	
}

void AGameController::SetPlayerHostCamera()
{
	
}

void AGameController::SpawnTokens()
{
	while (CurrentTokenCount < MaxTokenCount)
	{
		//TODO: Spawn new Tokens
	}
}

void AGameController::NextTurn()
{
	if (CurrentEntityIndex < Entities.Num())
	{
		CurrentEntityIndex++;
	} else {
		CurrentEntityIndex = 0;
	}
	OnNextTurn.Broadcast(Entities[CurrentEntityIndex]);
}

void AGameController::NextRound()
{
	CurrentRound++;
	RoundDamage.Add(0.0f);
	OnNextRound.Broadcast();

	//Calculate dmg per second
	float result = 0.0f;
	for (auto const Element : RoundDamage)
	{
		result += (float)Element;
	}
	DmgPerRound = result / CurrentRound;
	
	//Delete any tucked on players, which delayed their turn
	while(delayedTurns > 0)
	{
		Entities.Pop();
		delayedTurns--;
	}
}

AEntity* AGameController::GetCurrentEntity()
{
	return Entities[CurrentEntityIndex];
}

void AGameController::DelayEntityTurn(AEntity* entity)
{
	//Insert the Entity at the second-last position
	Entities.Insert(entity, Entities.Num()-2);
	delayedTurns++;
}

void AGameController::EndGame(const bool win)
{
	
}

// Called every frame
void AGameController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

