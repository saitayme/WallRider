#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "../Entity/Entity.h" // Assuming Entity class exists
#include <list> // For std::list
#include <map> // For std::map
#include <string> // For std::string
#include <algorithm> // For std::find
#include "../MapClasses/Room.h"

enum class BorderType { None, Wall, Locked, LockedWall };
enum class BehaviourType { Light, Fire, Sound, None };

UCLASS()
class YOURGAME_API ATile : public AActor
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
    void ChangeBehaviour(BehaviourType newBehaviour);

    UFUNCTION(BlueprintCallable, Category="Tile")
    bool HasShadewalker() const;

    UFUNCTION(BlueprintCallable, Category="Tile")
    ATile* Clone() const; // Implementing Clone method

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Tile", meta=(AllowPrivateAccess = "true"))
    float CrumValue;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Tile", meta=(AllowPrivateAccess = "true"))
    TArray<AEntity*> CurrentEntities;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Tile", meta=(AllowPrivateAccess = "true"))
    TMap<FString, BorderType> Borders;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Tile", meta=(AllowPrivateAccess = "true"))
    URoom* Room;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Tile", meta=(AllowPrivateAccess = "true"))
    BehaviourType CurrentBehaviour;

    UFUNCTION(BlueprintCallable, Category="Tile")
    bool HasEntity(AEntity* entity) const;

    UFUNCTION(BlueprintCallable, Category="Tile")
    AEntity* GetEntity() const;
};

