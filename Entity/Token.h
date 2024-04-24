#pragma once
#include "Entity.h"

using namespace std;

class Token : Entity
{
public:
	// Params
	FString IInteractable;

	// Functions
	static void Use(const FString& Entity, const FString& Instruction);
	void UpdateFieldCrums();
};
