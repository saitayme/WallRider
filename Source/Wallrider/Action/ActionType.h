// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ActionType.generated.h"


UENUM(BlueprintType)
enum class EActionType : uint8
{
	Interact = 0 UMETA(DisplayName = "INTERACT"),
	Move = 1 UMETA(DisplayName = "MOVE"),
	Investigate = 2 UMETA(DisplayName = "INVESTIGATE"),
	Pass = 3 UMETA(DisplayName = "PASS"),
	Delay = 4 UMETA(DisplayName = "DELAY")
};
