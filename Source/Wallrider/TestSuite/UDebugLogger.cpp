#include "UDebugLogger.h"

void UDebugLogger::Log(const FString& Message)
{
	UE_LOG(LogTemp, Warning, TEXT("%s"), *Message);
}