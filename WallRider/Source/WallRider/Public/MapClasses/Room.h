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
    Room(RoomType type); // Constructor now takes a RoomType
    ~Room();

    void Use(Entity* entity, const std::string& instruction);
    void AddEntity(Entity* entity);
    void RemoveEntity(Entity* entity);
    void TriggerSabotage();
    void SetRoomType(RoomType type); // Method to set the room type

private:
    std::vector<Entity*> Entities;
    std::function<void(Entity*, const std::string&)> ActOnUse;
    RoomType Type; // Added to store the room type
};

enum class RoomType {
    Laboratory, Hallway, Control, Portal, QuantumBox, Security, Electrical, Surgery, Stim, Nothing, Breakroom, Kitchen, Crematorium, Armory
};