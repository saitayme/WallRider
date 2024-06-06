// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "../Entity/AEntity.h" // Adjusted relative path
#include <list>
#include <map>
#include <string>
#include <algorithm>
#include "../MapClasses/Room.h"
#include "MapEnums.h" // Assuming BorderType and BehaviourType are defined here
#include "Tile.generated.h" // Move this line to be the last include

enum class BorderType { None, Wall, Locked, LockedWall };
enum class BehaviourType { Light, Fire, Sound, None };

UCLASS()
class WALLRIDER_API ATile : public AActor
{
    GENERATED_BODY()

public:
    ATile();
    virtual ~ATile();

    UFUNCTION(BlueprintCallable, Category="Tile")
    void ChangeCrums(float delta);

    UFUNCTION(BlueprintCallable, Category="Tile")
    void AddEntity(AEntity* entity);

    UFUNCTION(BlueprintCallable, Category="Tile")
    void RemoveEntity(AEntity* entity);

    UFUNCTION(BlueprintCallable, Category="Tile")
    void SetEdgeLocked(const FString& edge, bool locked);
    
    UFUNCTION(BlueprintCallable, Category="Tile")
    bool HasShadewalker() const;

    UFUNCTION(BlueprintCallable, Category="Tile")
    ATile* Clone() const; // Implementing Clone method

    UFUNCTION(BlueprintCallable, Category="Tile")
    const TArray<AEntity*>& GetCurrentEntities() const;

    UFUNCTION(BlueprintCallable, Category="Tile")
    TMap<FString, EBorderType> GetBorders() const;

    UFUNCTION(BlueprintCallable, Category="Tile")
    void SetRoom(URoom* newRoom);

    UFUNCTION(BlueprintCallable, Category="Tile")
    bool HasEntity(AEntity* entity) const;

    UFUNCTION(BlueprintCallable, Category="Tile")
    AEntity* GetEntity() const;

    UFUNCTION(BlueprintCallable, Category="Tile")
    void SetOnFire(bool bIsOnFire);

    UFUNCTION(BlueprintCallable, Category="Tile")
    void ChangeBehaviour(EBehaviourType newBehaviour);

    FVector GetLocation() const; // Changed to const

    float GetCrumValue() const;
    void BeginPlay();
    void ChangeBehaviour(BehaviourType newBehaviour);

    EBorderType GetBorder(const FString& Direction) const;

    bool ContainsEntity(AEntity* entity) const; // Added declaration for ContainsEntity

private:
    UPROPERTY(VisibleAnywhere, Category="Tile")
    float CrumValue;

    UPROPERTY(VisibleAnywhere, Category="Tile")
    TArray<AEntity*> CurrentEntities;

    UPROPERTY(VisibleAnywhere, Category="Tile")
    TMap<FString, EBorderType> Borders;

    UPROPERTY(VisibleAnywhere, Category="Tile")
    URoom* room;

    BehaviourType currentBehaviour;
};
