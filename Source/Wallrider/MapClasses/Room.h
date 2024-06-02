// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MapEnums.h"
#include "UObject/Object.h"
#include "Wallrider/UInteractable.h"
#include "Wallrider/UInvestigatable.h"
#include "WallRider/Entity/AEntity.h"
#include "Room.generated.h"

/**
 * 
 */
UCLASS()
class WALLRIDER_API URoom : public UObject, public IInteractable, public IInvestigatable
// Commented out to test forward declaration
// class WALLRIDER_API URoom : public UObject, public IInteractable
{
	GENERATED_BODY()
	
public:

	UPROPERTY(BlueprintReadWrite, Category="Stats")
	ERoomType RoomType;
	
	//UPROPERTY(BlueprintReadWrite, Category="Stats")
	//UDelegateFunction ActOnUse;

	EFactionType SabotageFaction;

	UFUNCTION(BlueprintCallable, Category="Session")
	virtual void Interacted(AEntity* Other) override;
	virtual EFactionType Investigated() override;

	UFUNCTION(BlueprintCallable, Category="Session")
	void Sabotage(EFactionType Faction);

	UFUNCTION(BlueprintCallable, Category="Session")
	void MassSabotage();

	UFUNCTION(BlueprintCallable, Category="Session")
	void AddEntity(AEntity* Entity);

	UFUNCTION(BlueprintCallable, Category="Session")
	void RemoveEntity(FString EntityId);

private:

	TMap<FString, AEntity*> Entities;

};
