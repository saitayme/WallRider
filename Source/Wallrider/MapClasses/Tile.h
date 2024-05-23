// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MapEnums.h"
#include "Room.h"
#include "GameFramework/Actor.h"
#include "Tile.generated.h"

UCLASS()
class WALLRIDER_API ATile : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ATile();

	UFUNCTION(BlueprintCallable, Category="Session")
	void SetEdgeLocked(EEdgeType Edge, bool Locked);

	UFUNCTION(BlueprintCallable, Category="Stats")
	bool HasShadewalker();

	UFUNCTION(BlueprintCallable, Category="Stats")
	TArray<AEntity*> GetCurrentEntities();
	
	UFUNCTION(BlueprintCallable, Category="Stats")
	TMap<EEdgeType, EBorderType> GetBorders();

	UFUNCTION(BlueprintCallable, Category="Stats")
	EBorderType GetBorder(const EEdgeType Direction);

	UFUNCTION(BlueprintCallable, Category="Stats")
	void ChangeCrumValue(float delta);

	void SetRoom(URoom* Room);
	
	float GetCrumValue();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
private:
	
	UPROPERTY(BlueprintReadOnly, Category="Stats", meta = (AllowPrivateAccess = "true"))
	float CrumValue;
	
	TArray<AEntity*> CurrentEntities;
	TMap<EEdgeType, EBorderType> Borders;
	URoom* CurrentRoom;

	UFUNCTION(BlueprintCallable, Category="Session", meta = (AllowPrivateAccess = "true"))
	void AddEntity(AEntity* Entity);
	
	UFUNCTION(BlueprintCallable, Category="Session", meta = (AllowPrivateAccess = "true"))
	void RemoveEntity(AEntity* Entity);
	
	ATile* Clone();
	
};
