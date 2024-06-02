// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EFactionType.h"
#include "GameFramework/Actor.h"
#include "Wallrider/UInteractable.h"
#include "WallRider/Action/EActionType.h"
#include "AEntity.generated.h"

UCLASS()
class WALLRIDER_API AEntity : public AActor, public IInteractable
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AEntity();

	UPROPERTY(BlueprintReadWrite, Category="Stats")
	FString EntityId;

	UPROPERTY(BlueprintReadWrite, Category="Stats")
	int MaxActionCount;

	UPROPERTY(BlueprintReadWrite, Category="Stats")
	int MaxHP;

	UPROPERTY(BlueprintReadWrite, Category="Stats")
	EFactionType Faction;

	UPROPERTY(BlueprintReadOnly, Category="Stats", meta = (AllowPrivateAccess = "true"))
	int XLocation;

	UPROPERTY(BlueprintReadOnly, Category="Stats", meta = (AllowPrivateAccess = "true"))
	int YLocation;

	// Events (also available in blueprints)
	
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPossessed, AEntity*, currentEntityRef);

	UPROPERTY(BlueprintAssignable, EditAnywhere, Category="Actions")
	FOnPossessed OnPossessed;
	
	UFUNCTION(BlueprintCallable, Category="Stats")
	virtual void Damage(const int Value);
	
	const TMap<EActionType, int> BaseActionBuffs;

	
	TMap<EActionType, int> CurrentActionBuffs;

	UFUNCTION(BlueprintCallable, Category="Stats")
	void BuffAction(const TMap<EActionType, int>& Buff);

	UFUNCTION(BlueprintCallable, Category="Stats")
	virtual void Interact(TScriptInterface<IInteractable> Other);

	virtual void Interacted(AEntity* Other) override;
	
	virtual void Move(int Direction);
	
	UFUNCTION(BlueprintCallable, Category="Logging")
	void Log(const FString& S);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category="Stats", meta = (AllowPrivateAccess = "true"))
	int XIndex;

	UPROPERTY(BlueprintReadOnly, Category="Stats", meta = (AllowPrivateAccess = "true"))
	int YIndex;

	UPROPERTY(BlueprintReadOnly, Category="Stats", meta = (AllowPrivateAccess = "true"))
	int CurrentActionCount;

	UPROPERTY(BlueprintReadOnly, Category="Stats", meta = (AllowPrivateAccess = "true"))
	int CurrentHP;

	UFUNCTION(BlueprintCallable, Category="Turn", meta = (AllowPrivateAccess = "true"))
	void OnNextRound();

	UFUNCTION(BlueprintCallable, Category="Turn", meta = (AllowPrivateAccess = "true"))
	void OnTurnStart(AEntity* Entity);

private: 
	
	
};
