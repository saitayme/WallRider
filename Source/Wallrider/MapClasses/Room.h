// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MapEnums.h"
#include "UObject/Object.h"
#include "Wallrider/UInteractable.h"
#include "WallRider/Entity/AEntity.h"
#include "Room.generated.h"

// Forward declaration to resolve circular dependency
class ATile;

/**
 * 
 */
UCLASS()
class WALLRIDER_API URoom : public UObject, public IInteractable
{
	GENERATED_BODY()
	
public:

	UPROPERTY(BlueprintReadWrite, Category="Stats")
	ERoomType RoomType;
	
	//UPROPERTY(BlueprintReadWrite, Category="Stats")
	//UDelegateFunction ActOnUse;

	// Add a public getter for Entities
    const TMap<FString, AEntity*>& GetEntities() const { return Entities; }

	UFUNCTION(BlueprintCallable, Category="Session")
	void Use(AEntity* Entity, const FString Instructions);

	UFUNCTION(BlueprintCallable, Category="Session")
	void Sabotage();

	UFUNCTION(BlueprintCallable, Category="Session")
	void MassSabotage();

	UFUNCTION(BlueprintCallable, Category="Session")
	void AddEntity(AEntity* Entity);

	UFUNCTION(BlueprintCallable, Category="Session")
	void RemoveEntity(FString EntityId);

	virtual void Interacted(UObject* Other) override;
	virtual void Investigated(UObject* Other) override;

	ATile* GetRandomTile();
	TArray<ATile*> GetAllTiles();

private:

	TMap<FString, AEntity*> Entities;
	bool IsSabotaged;

};
