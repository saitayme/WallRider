#pragma once
#include "Entity.h"

class Player : Entity
{
public:
	// Params
	FString IInteractable = "";
	
	// TODO: check if there are unreal methods for this
	std::list<FString> Inventory;
	
	FString EventOnDamageTaken;

	// Functions
	void Construct(FString DataContainer);
	static void Use(const FString& Entity, const FString& Instruction);
	void UpdateFieldCrums();
};
