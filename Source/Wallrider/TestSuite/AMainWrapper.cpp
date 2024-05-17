#include "AMainWrapper.h"
#include "../Entity/PlayerEntity.h"

// Sets default values
AMainWrapper::AMainWrapper()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMainWrapper::BeginPlay()
{
	Super::BeginPlay();
}