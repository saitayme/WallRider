#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AMainWrapper.generated.h"

UCLASS()
class WALLRIDER_API AMainWrapper : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMainWrapper();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
