#pragma once

#include "UInteractable.generated.h"

UINTERFACE()
class UInteractable : public UInterface
{
	GENERATED_BODY()
};

class IInteractable 
{
	GENERATED_BODY()

	virtual void Interacted(UObject Other) = 0;
	virtual void Investigated(UObject Other) = 0;
};
