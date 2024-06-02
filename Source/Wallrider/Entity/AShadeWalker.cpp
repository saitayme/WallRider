// AShadeWalker.cpp
#include "AShadeWalker.h"

AShadeWalker::AShadeWalker()
{
	// Override Member variables from AEntity
	MaxActionCount = 3;
	MaxHP = 1;
	Faction = EFactionType::ShadeWalker;
}

void AShadeWalker::BeginPlay()
{
	Super::BeginPlay();
}

void AShadeWalker::Tick(const float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AShadeWalker::Interacted(AEntity* Other)
{
	Damage(1);
}
