

#include "CoreMinimal.h"
#include "../Entity/Entity.h" // Assuming Entity class exists
#include <functional> // For std::function
#include <vector> // For std::vector

UENUM(BlueprintType)
enum class ERoomType : uint8 {
    Laboratory, Hallway, Control, Portal, QuantumBox, Security, Electrical, Surgery, Stim, Nothing, Breakroom, Kitchen, Crematorium, Armory
};

UCLASS()
class WALLRIDER_API URoom : public UObject
{
    GENERATED_BODY()

public:
    URoom(ERoomType Type); // Constructor now takes a RoomType
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
    void SetRoomType(ERoomType Type); // Method to set the room type

private:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Room", meta=(AllowPrivateAccess = "true"))
    TArray<AEntity*> Entities;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Room", meta=(AllowPrivateAccess = "true"))
    ERoomType Type; // Added to store the room type
};
