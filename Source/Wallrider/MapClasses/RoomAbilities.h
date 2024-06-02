#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Room.h"
#include "RoomAbilities.generated.h"

UCLASS()
class WALLRIDER_API ARoomAbilities : public AActor
{
    GENERATED_BODY()

public:
    static void ActivateAbility(URoom* Room);
private:
    static void ActivateLaboratory(URoom* Room);
    static void ActivateControl(URoom* Room);
    static void ActivatePortal(URoom* Room);
    static void ActivateQuantumBox(URoom* Room);
    static void ActivateSecurity(URoom* Room);
    static void ActivateElectrical(URoom* Room);
    static void ActivateSurgery(URoom* Room);
    static void ActivateStim(URoom* Room);
    static void ActivateBreakroom(URoom* Room);
    static void ActivateKitchen(URoom* Room);
    static void ActivateCrematorium(URoom* Room);
    static void ActivateArmory(URoom* Room);
};
    // Add declarations for other room types