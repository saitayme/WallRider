// Fill out your copyright notice in the Description page of Project Settings.


#include "Item.h"

#include "Wallrider/Entity/AEntity.h"
#include "WallRider/Entity/FactionType.h"

UItem::UItem()
{
	SabotageFaction = EFactionType::Neutral;
}

void UItem::Interacted(UObject* Other)
{
	
	if (AEntity* OtherEntity = Cast<AEntity>(Other))
	{
		AssignItemToPlayer(OtherEntity);
		
		OnItemInteracted.Broadcast();

		if (SabotageFaction != EFactionType::Neutral) {
			
			OtherEntity->Damage(1);
			SabotageFaction = EFactionType::Neutral;
		}

	} else {
		UE_LOG(LogTemp, Warning, TEXT("%s cannot interact with %s"), *Other->GetName(), *this->GetName());
		return;
	}
	
}

EFactionType UItem::Investigated(UObject* Other)
{
	const EFactionType BufferFaction = SabotageFaction;
	SabotageFaction = EFactionType::Neutral;
	return BufferFaction;
}

void UItem::AssignItemToPlayer(AEntity* Player)
{
	Owner = Player;
}

void UItem::Sabotage(const EFactionType Faction)
{
	SabotageFaction = Faction;
}
