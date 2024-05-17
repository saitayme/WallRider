// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "FactionType.generated.h"



UENUM(BlueprintType)
enum class EFactionType : uint8
{
	Neutral = 0 UMETA(DisplayName = "Neutra") /* Used for AEntity.cpp Members initialization */,
	Player = 0 UMETA(DisplayName = "PLAYER"),
	ShadeWalker = 1 UMETA(DisplayName = "SHADEWALKER"),
	Possessed = 2 UMETA(DisplayName = "POSSESSED"),
	Token = 3 UMETA(DisplayName = "TOKEN")
};
