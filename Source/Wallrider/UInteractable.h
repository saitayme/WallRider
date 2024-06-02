#pragma once
#include "Entity/EFactionType.h"

#include "UInteractable.generated.h"

class AEntity;

UINTERFACE()
class UInteractable : public UInterface
{
	GENERATED_BODY()
};

class IInteractable 
{
	GENERATED_BODY()

public:
	virtual void Interacted(AEntity* Other) = 0;
};
