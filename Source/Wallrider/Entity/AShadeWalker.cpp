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

void AShadeWalker::Tick(const float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AShadeWalker::Interacted(AEntity* Other)
{
	if (AEntity* OtherEntity = Cast<AEntity>(Other))
	{
		// Damage the player who interacted with the ShadeWalker
		OtherEntity->Damage(1); // Replace 1 with the amount of damage you want to inflict
	}
}

void AShadeWalker::Investigated(AEntity* Other)
{
	if (const AEntity* OtherEntity = Cast<AEntity>(Other))
	{
		UE_LOG(LogTemp, Warning, TEXT("%s investigated %s"), *OtherEntity->GetName(), *this->GetName());
	}
}
