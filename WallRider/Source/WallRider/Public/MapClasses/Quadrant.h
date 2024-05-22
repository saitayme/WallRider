#pragma once

#include "CoreMinimal.h"
#include "Tile.h" // Adjust the include path as necessary
#include "Quadrant.generated.h"

UCLASS()
class WALLRIDER_API UQuadrant : public UObject
{
    GENERATED_BODY()

public:
    UQuadrant();
    virtual ~UQuadrant();

    UFUNCTION(BlueprintCallable, Category="Quadrant")
    void LockQuadrant();

    UFUNCTION(BlueprintCallable, Category="Quadrant")
    bool CheckIfShadewalkerPresent() const;

    UFUNCTION(BlueprintCallable, Category="Quadrant")
    unsigned int GetQuadrantId() const { return QuadrantId; }

private:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Quadrant", meta=(AllowPrivateAccess = "true"))
    unsigned int QuadrantId;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Quadrant", meta=(AllowPrivateAccess = "true"))
    TArray<ATile*> Bounds;
};
