﻿// Fill out your copyright notice in the Description page of Project Settings.


#include "ChargedItem.h"

UChargedItem::UChargedItem()
{
	CurrentCharges = MaxCharges;
}

void UChargedItem::Interacted(AEntity* Other)
{
	if (CurrentCharges == 0) {
	
		OnChargesEmpty.Broadcast();

	} else {
		CurrentCharges = CurrentCharges - 1;
		Super::Interacted(Other);
	}
}


