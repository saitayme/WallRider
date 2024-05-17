// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UInteractable.h"
#include "GameFramework/Actor.h"
#include "Wallrider/Entity/FactionType.h"
#include "Token.generated.h"

UCLASS()
class WALLRIDER_API AToken : public AActor, public IInteractable
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AToken();
	
	UPROPERTY(BlueprintReadWrite, Category="Stats")
	EFactionType Faction;

	UPROPERTY(BlueprintReadOnly, Category="Stats", meta = (AllowPrivateAccess = "true"))
	int XLocation;

	UPROPERTY(BlueprintReadOnly, Category="Stats", meta = (AllowPrivateAccess = "true"))
	int YLocation;

	//FUNCTIONS
	
	virtual void Interacted(UObject* Other) override;
	virtual void Investigated(UObject* Other) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	

};
