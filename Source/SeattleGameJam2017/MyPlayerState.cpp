// Fill out your copyright notice in the Description page of Project Settings.

#include "MyPlayerState.h"
#include "InventoryComponent.h"
#include "InventoryItem.h"

AMyPlayerState::AMyPlayerState()
{
	InventoryComponent = NewObject<UInventoryComponent>();

	OnPlayerDeath.AddUniqueDynamic(this, &AMyPlayerState::ProcessPlayerDeath);
}

UInventoryComponent* AMyPlayerState::GetInventoryComponent() const
{
	if (!ensure(InventoryComponent)) { return nullptr; }

	return InventoryComponent;
}

void AMyPlayerState::SellItem(UInventoryItem* ItemToSell)
{
	if (!ensure(InventoryComponent) || !ensure(ItemToSell)) { return; }

	CurrentDeathChance += ItemToSell->GetDeathChance();
	CurrentMoney += InventoryComponent->SellItem(ItemToSell);
	
	auto DeathRoll = FMath::RandRange(0.f, 1.f);
	UE_LOG(LogTemp, Warning, TEXT("Death Roll: Rolled %f, Chance was %f."), DeathRoll, CurrentDeathChance);
	if (DeathRoll < CurrentDeathChance)
	{
		OnPlayerDeath.Broadcast();
		UE_LOG(LogTemp, Warning, TEXT("Player died."));
	}

	UE_LOG(LogTemp, Warning, TEXT("Player sold item."));
}