// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
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
class WALLRIDER_API URoom : public UObject
{
    GENERATED_BODY()

public:
    URoom();
    URoom(ERoomType Type);
    URoom(const FObjectInitializer& ObjectInitializer);
    virtual ~URoom();

    UFUNCTION(BlueprintCallable, Category="Room")
    void Use(AEntity* Entity, const FString& Instruction);

    UFUNCTION(BlueprintCallable, Category="Room")
    void AddEntity(AEntity* Entity);

    UFUNCTION(BlueprintCallable, Category="Room")
    void RemoveEntity(AEntity* Entity);

    UFUNCTION(BlueprintCallable, Category="Room")
    void TriggerSabotage();

    UFUNCTION(BlueprintCallable, Category="Room")
    void SetRoomType(ERoomType Type);
	
    UPROPERTY(VisibleAnywhere, Category="Room")
    TArray<AEntity*> Entities;

    UPROPERTY(VisibleAnywhere, Category="Room")
    ERoomType Type;

    ATile* GetRandomTile();
    TArray<ATile*> GetAllTiles();
    TArray<AEntity*> GetEntities() const;

    void Sabotage();
    void MassSabotage();
    void Interacted(UObject* Other);
    void Investigated(UObject* Other);

private:
    TArray<ATile*> Tiles; // Array to store pointers to tiles
};
