#pragma once
#include "AbstractAction.h"
#include "WallRider/Entity/Entity.h"

namespace Action
{
	class Move : AbstractAction
	{
		float CrumTrial = 0.0f;

	public:
		// TODO recherche signature usage
		virtual void Act(const FString& Instructions) override;
	};
}
