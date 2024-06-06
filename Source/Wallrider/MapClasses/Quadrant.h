#pragma once

// Forward declarations
class ATile;

#include "CoreMinimal.h"
#include "Quadrant.generated.h"

UCLASS()
class WALLRIDER_API UQuadrant : public UObject
{
    GENERATED_BODY()

public:
    UQuadrant();
    UQuadrant(unsigned int QuadrantId, TArray<ATile*> bounds);

    UFUNCTION(BlueprintCallable, Category="Quadrant")
    void LockQuadrant();

    UFUNCTION(BlueprintCallable, Category="Quadrant")
    bool CheckIfShadewalkerPresent() const;

    unsigned int GetQuadrantId() const;

private:
    UPROPERTY(VisibleAnywhere, Category="Quadrant")
    unsigned int QuadrantId;

    UPROPERTY(VisibleAnywhere, Category="Quadrant")
    TArray<ATile*> bounds;
};
