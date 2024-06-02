// AShadeWalker.h
#pragma once

#include "CoreMinimal.h"
#include "AEntity.h"
#include "AShadeWalker.generated.h"

UCLASS()
class WALLRIDER_API AShadeWalker : public AEntity
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AShadeWalker();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Override the Interacted function
	virtual void Interacted(AEntity* Other) override;
};
