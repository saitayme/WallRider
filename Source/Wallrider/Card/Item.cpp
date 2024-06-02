// Fill out your copyright notice in the Description page of Project Settings.


#include "Item.h"

#include "Wallrider/Entity/AEntity.h"

UItem::UItem()
{
}

void UItem::Interacted(AEntity* Other)
{
		
	OnItemInteracted.Broadcast();
}

void UItem::AssignItemToPlayer(AEntity* Player)
{
	Owner = Player;
}
