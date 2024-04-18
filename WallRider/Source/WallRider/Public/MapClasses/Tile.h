// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Entity.h" // Assuming Entity class exists
#include <list> // For std::list
#include <map> // For std::map
#include <string> // For std::string

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

private:
    float CrumValue;
    std::list<Entity*> CurrentEntities;
    std::map<std::string, BorderType> Borders;
    Room* room;
    BehaviourType currentBehaviour = BehaviourType::None;
};
