#pragma once

#include "CoreMinimal.h"
#include "WallRider/Entity/Entity.h"

namespace Action
{
	class AbstractAction
	{
	public:
		// Params
		Entity* Owner;
		unsigned int Buff;
	
		// For some reason needs default constructor and destructor
		AbstractAction();
		virtual ~AbstractAction();

		virtual void Act(const FString& Instructions) = 0;
	};

}
