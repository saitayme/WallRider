﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FactionType.h"
#include "GameFramework/Actor.h"
#include "WallRider/Action/ActionType.h"
#include "WallRider/Action/BaseAction.h"
#include "AEntity.generated.h"

UCLASS()
class WALLRIDER_API AEntity : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AEntity();

	UPROPERTY(BlueprintReadWrite, Category="Stats")
	FString EntityId;

	UPROPERTY(BlueprintReadWrite, Category="Stats")
	int MaxActionCount;

	UPROPERTY(BlueprintReadWrite, Category="Stats")
	int MaxHP;

	UPROPERTY(BlueprintReadWrite, Category="Stats")
	EFactionType Faction;

	UPROPERTY(BlueprintReadWrite, Category="Actions")
	TArray<UBaseAction*> Actions;

	//EVENTS (also available in blueprints)
	
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPossessed, AEntity*, currentEntityRef);

	UPROPERTY(BlueprintAssignable, EditAnywhere, Category="Actions")
	FOnPossessed OnPossessed;



	UFUNCTION(BlueprintCallable, Category="Stats")
	virtual void Damage(const int value);

	UFUNCTION(BlueprintCallable, Category="Stats")
	void BuffAction(const TMap<EActionType,int>& Buff);
	//TODO: Change this with actions

	UFUNCTION(BlueprintCallable, Category="Actions")
	void Interact(const FString& IInteractable);
	//TODO: Change this with an actual interface
	
	UFUNCTION(BlueprintCallable, Category="Actions")
	void Act(const UBaseAction* Action);

	UFUNCTION(BlueprintCallable, Category="Logging")
	void Log(const FString& s);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category="Stats", meta = (AllowPrivateAccess = "true"))
	int xIndex;

	UPROPERTY(BlueprintReadOnly, Category="Stats", meta = (AllowPrivateAccess = "true"))
	int yIndex;

	UPROPERTY(BlueprintReadOnly, Category="Stats", meta = (AllowPrivateAccess = "true"))
	int CurrentActionCount;

	UPROPERTY(BlueprintReadOnly, Category="Stats", meta = (AllowPrivateAccess = "true"))
	int CurrentHP;

	UFUNCTION(BlueprintCallable, Category="Turn", meta = (AllowPrivateAccess = "true"))
	void OnNextRound();

	UFUNCTION(BlueprintCallable, Category="Turn", meta = (AllowPrivateAccess = "true"))
	void OnTurnStart(AEntity* Entity);

private: 
	
	
};