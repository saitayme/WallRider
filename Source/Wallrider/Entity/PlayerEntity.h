﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AEntity.h"
#include "PlayerEntity.generated.h"

	
UCLASS()
class WALLRIDER_API APlayerEntity : public AEntity
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	APlayerEntity();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	
	virtual void Damage(const int value) override;
};