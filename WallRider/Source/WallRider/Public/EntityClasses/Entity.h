#pragma once

#include "CoreMinimal.h"

class Room; // Forward declaration to avoid circular dependency

class WALLRIDER_API Entity {
public:
    Entity();
    virtual ~Entity();

    void SetCurrentRoom(Room* room);
    Room* GetCurrentRoom() const;

    virtual bool IsShadewalker() const { return false; } // Added method

private:
    Room* CurrentRoom;
};