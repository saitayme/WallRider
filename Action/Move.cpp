#include "Move.h"

#include "WallRider/TestSuite/UDebugLogger.h"

namespace Action
{
	void Move::Act(const FString& Instruction)
	{
		FString output = FString::Printf(TEXT("Move::Act called with: %s"), *Instruction);
		UDebugLogger::Log(output);
	}
}
