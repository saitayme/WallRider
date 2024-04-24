#include "Player.h"
#include "../TestSuite//UDebugLogger.h"

void Player::Use(const FString& Entity, const FString& Instruction)
{
	FString output = FString::Printf(TEXT("Player::Use called with: %s %s"), *Entity, *Instruction);
	UDebugLogger::Log(output);
}
