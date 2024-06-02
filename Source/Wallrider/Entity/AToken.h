// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "APlayerEntity.h"
#include "GameFramework/Actor.h"
#include "Wallrider/UInvestigatable.h"
#include "AToken.generated.h"

UCLASS()
class WALLRIDER_API AToken : public AEntity, public IInvestigatable
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AToken();

	// Functions

	EFactionType SabotageFaction;

	void Sabotage(EFactionType OtherFaction);
	
	virtual void Interacted(AEntity* Other) override;
	virtual EFactionType Investigated() override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
private:
	FString Item; // The item that this token represents
	static const TArray<FString> ItemList; // The list of possible items
	
	void Use(const APlayerEntity* PlayerEntity) const; // The function to use the item
};
