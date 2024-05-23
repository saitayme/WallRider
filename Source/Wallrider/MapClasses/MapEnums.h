// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "MapEnums.generated.h"

UENUM(BlueprintType)
enum class EEdgeType : uint8
{
	West = 0 UMETA(DisplayName = "WEST"),
	North = 1 UMETA(DisplayName = "NORTH"),
	East = 2 UMETA(DisplayName = "EAST"),
	South = 3 UMETA(DisplayName = "SOUTH"),
};

UENUM(BlueprintType)
enum class EBorderType : uint8
{
	None = 0 UMETA(DisplayName = "NONE"),
	Wall = 1 UMETA(DisplayName = "WALL"),
	Locked = 2 UMETA(DisplayName = "LOCKED"),
	LockedWall = 3 UMETA(DisplayName = "LOCKEDWALL"),
};

UENUM(BlueprintType)
enum class ERoomType : uint8
{
	Laboratory = 0 UMETA(DisplayName = "Laboratory"),
	Hallway = 1 UMETA(DisplayName = "Hallway"),
	Control = 2 UMETA(DisplayName = "Control"),
	Portal = 3 UMETA(DisplayName = "Portal"),
	QuantumBox = 4 UMETA(DisplayName = "QuantumBox"),
	Security = 5 UMETA(DisplayName = "Security"),
	Electrical = 6 UMETA(DisplayName = "Electrical"),
	Surgery = 7 UMETA(DisplayName = "Surgery"),
	Stim = 8 UMETA(DisplayName = "Stim"),
	Nothing = 9 UMETA(DisplayName = "Nothing"),
	Breakroom = 10 UMETA(DisplayName = "Breakroom"),
	Kitchen = 11 UMETA(DisplayName = "Kitchen"),
	Crematorium = 12 UMETA(DisplayName = "Crematorium"),
	Armory = 13 UMETA(DisplayName = "Armory")
};
