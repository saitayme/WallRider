// AShadeWalker.cpp
#include "AShadeWalker.h"

AShadeWalker::AShadeWalker()
{
	MaxActionCount = 3;
	MaxHP = 1;
	Faction = EFactionType::ShadeWalker;
}

void AShadeWalker::BeginPlay()
{
	Super::BeginPlay();
}

void AShadeWalker::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AShadeWalker::Interacted(UObject* Other)
{
	if (AEntity* OtherEntity = Cast<AEntity>(Other))
	{
		// Damage the player who interacted with the ShadeWalker
		OtherEntity->Damage(1); // Replace 1 with the amount of damage you want to inflict
	}
}
