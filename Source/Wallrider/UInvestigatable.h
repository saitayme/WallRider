#pragma once
#include "Entity/EFactionType.h"

#include "UInvestigatable.generated.h"

UINTERFACE()
class UInvestigatable : public UInterface
{
	GENERATED_BODY()
};

class IInvestigatable 
{
	GENERATED_BODY()

public:
	virtual EFactionType Investigated() = 0;
};
