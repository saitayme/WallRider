// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../Entity/Entity.h" // Assuming Entity class exists
#include <list> // For std::list
#include <map> // For std::map
#include <string> // For std::string
#include <algorithm> // For std::find
#include "../MapClasses/Room.h"

enum class BorderType { None, Wall, Locked, LockedWall };
enum class BehaviourType { Light, Fire, Sound, None };

class WALLRIDER_API Tile
{
public:
    Tile();
    ~Tile();

    void ChangeCrums(float delta);
    void AddEntity(Entity* entity);
    void RemoveEntity(Entity* entity);
    void SetEdgeLocked(const std::string& edge, bool locked);
    void ChangeBehaviour(BehaviourType newBehaviour);
    bool HasShadewalker() const;
    Tile* Clone() const; // Implementing Clone method

    // Adding public getter for CurrentEntities
    const std::list<Entity*>& GetCurrentEntities() const { return CurrentEntities; }
    // Adding public getter for Borders
    std::map<std::string, BorderType> GetBorders() const { return Borders; }
    void SetRoom(Room* newRoom) { this->room = newRoom; } // Fixed shadowing issue

    // Implementing HasEntity method
    bool HasEntity(Entity* entity) const {
        return std::find(CurrentEntities.begin(), CurrentEntities.end(), entity) != CurrentEntities.end();
    }

    // Added GetEntity method
    Entity* GetEntity() const {
        if (!CurrentEntities.empty()) {
            return *CurrentEntities.begin(); // Return the first entity
        }
        return nullptr; // Return nullptr if there are no entities
    }

private:
    float CrumValue;
    std::list<Entity*> CurrentEntities;
    std::map<std::string, BorderType> Borders;
    Room* room;
    BehaviourType currentBehaviour = BehaviourType::None;
};
