#pragma once

#include "CoreMinimal.h"
#include "UDebugLogger.generated.h"

UCLASS()
class WALLRIDER_API UDebugLogger : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Debug")
	static void Log(const FString& Message);
};
