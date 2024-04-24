#pragma once
#include <map>

enum class FactionType {
    Player, Posessed, Shadewalker
};

class Entity
{
public:
	// Constructor
	// Entities();
	
	// Parameters
	FString EntityId;
	int HP;
	unsigned int ActionsCount;

	// TODO: check different unreal methods
	// using map<FString, FString> as placeholder for map<ActionType, Action>
	// using ActionType = void(*)(const FString&, const FString&);
	// std::map<FString, ActionType> Dictionary;
	
	int TileLocation[9][9];
	FactionType FactionType;

	// Functions
	void Interact(FString IInteractable);
	void Act(std::map<FString, FString>);
	void OnTurnFinished();
	void BuffAction(std::map<FString, FString>);
};
