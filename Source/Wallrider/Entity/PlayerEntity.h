﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AEntity.h"
#include "PlayerEntity.generated.h"

	
UCLASS()
class WALLRIDER_API APlayerEntity : public AEntity, public IInteractable
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	APlayerEntity();

	virtual void Interacted(UObject* Other) override;
	virtual EFactionType Investigated(UObject* Other) override;

	virtual void Damage(const int Value) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	
	
};