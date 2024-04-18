// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Entity.h" // Assuming Entity class exists
#include <functional> // For std::function
#include <vector> // For std::vector

/**
 * 
 */
class WALLRIDER_API Room
{
public:
    Room();
    ~Room();

    void Use(Entity* entity, const std::string& instruction);
    void AddEntity(Entity* entity);
    void RemoveEntity(Entity* entity);
    void TriggerSabotage();

private:
    std::vector<Entity*> Entities;
    std::function<void(Entity*, const std::string&)> ActOnUse;
};
