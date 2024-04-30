// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "WallRider/Entity/AEntity.h"
#include "WallRider/MapClasses/Board.h"
#include "Wallrider/GameMode/PlayerHostController.h"
#include "GameController.generated.h"

UCLASS()
class WALLRIDER_API AGameController : public AGameModeBase
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Setup")
	APlayerHostController* PlayerHostControllerRef;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Setup")
	TArray<AEntity*> Entities;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category= "Setup")
	ABoard* Board;
	
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category= "Session")
	int CurrentRound = 0;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category= "Session")
	int CurrentTokenCount = 0;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category= "Session")
	TArray<int> RoundDamage;


	//EVENTS (also available in blueprints)
	
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnNextTurn, AEntity*, currentEntityRef);

	UPROPERTY(BlueprintAssignable, EditAnywhere, Category="Session")
	FOnNextTurn OnNextTurn;
	
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnNextRound);

	UPROPERTY(BlueprintAssignable, EditAnywhere, Category="Session")
	FOnNextRound OnNextRound;
	
	//FUNCTIONS
	
	// Sets default values for this actor's properties
	AGameController();
	virtual void Tick(float DeltaTime) override;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Session")
	void NextTurn();
	
	UFUNCTION(BlueprintCallable, Category = "Session")
	void NextRound();
	
	UFUNCTION(BlueprintCallable, Category = "Session")
	AEntity* GetCurrentEntity();
	
	UFUNCTION(BlueprintCallable, Category = "Session")
	void DelayEntityTurn(AEntity* entity);

	UFUNCTION(BlueprintCallable, Category = "Session")
	void EndGame(const bool win);

private:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category= "Session", meta = (AllowPrivateAccess = "true"))
	float DmgPerRound = 0.0f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category= "Session", meta = (AllowPrivateAccess = "true"))
	int CurrentEntityIndex = 0;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category= "Session", meta = (AllowPrivateAccess = "true"))
	int MaxTokenCount = 0;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<AEntity> EntityToSpawn;

	int delayedTurns = 0;

	void SetEntitiesRef(const int playerCount);

	void SetPlayerHostControllerRef();

	void SetMapRef();

	void SpawnEntities();

	void SetPlayerHostCamera();

	void SpawnTokens();
};