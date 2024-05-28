#pragma once

#include "UInteractable.generated.h"

enum class EFactionType : uint8;

UINTERFACE()
class UInteractable : public UInterface
{
	GENERATED_BODY()
};

class IInteractable 
{
	GENERATED_BODY()

	virtual void Interacted(UObject* Other) = 0;
	virtual EFactionType Investigated(UObject* Other) = 0;
};
