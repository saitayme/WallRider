﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayerEntity.h"
#include "Wallrider/UInteractable.h"
#include "GameFramework/Actor.h"
#include "Wallrider/Entity/FactionType.h"
#include "AToken.generated.h"

UCLASS()
class WALLRIDER_API AToken : public AActor, public IInteractable
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AToken();
	
	UPROPERTY(BlueprintReadWrite, Category="Stats")
	EFactionType Faction;

	UPROPERTY(BlueprintReadOnly, Category="Stats", meta = (AllowPrivateAccess = "true"))
	int XLocation;

	UPROPERTY(BlueprintReadOnly, Category="Stats", meta = (AllowPrivateAccess = "true"))
	int YLocation;

	// Functions
	
	virtual void Interacted(AEntity* Other) override;
	virtual void Investigated(AEntity* Other) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
private:
	FString Item; // The item that this token represents
	static const TArray<FString> ItemList; // The list of possible items
	
	void Use(const APlayerEntity* PlayerEntity) const; // The function to use the item
};
