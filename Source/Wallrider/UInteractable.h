#pragma once

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

	virtual void Interacted(AEntity* Other) = 0;
	virtual void Investigated(AEntity* Other) = 0;
};
