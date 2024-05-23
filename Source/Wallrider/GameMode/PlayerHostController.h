// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PlayerHostController.generated.h"

UCLASS()
class WALLRIDER_API APlayerHostController : public APlayerController
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	APlayerHostController();

	void SelectCurrentPlayer();

	void DisplayValidFields();

	void MoveCurrentPlayer();

	void Interact();

	void InteractWithRoom();

	void InteractWithItem();

	void SabotageRoom();

	void InvestigateRoom();

	void UseEnergyCage();

	void PassTurn();

	void DelayTurn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
