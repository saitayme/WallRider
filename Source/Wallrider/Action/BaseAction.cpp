// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseAction.h"

void UBaseAction::Act(FString Instructions)
{
	Log("Performed");
}

void UBaseAction::Log(const FString& s)
{
	UE_LOG(LogTemp, Warning, TEXT("%s: %s"), *this->GetClass()->GetName(), *s);
}