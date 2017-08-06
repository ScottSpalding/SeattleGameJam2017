// Fill out your copyright notice in the Description page of Project Settings.

#include "MyPlayerState.h"
#include "InventoryComponent.h"
#include "InventoryItem.h"

void AMyPlayerState::Initialize()
{
	UE_LOG(LogTemp, Warning, TEXT("Creating Inventory Component..."));
	InventoryComponent = NewObject<UInventoryComponent>();
	UE_LOG(LogTemp, Warning, TEXT("Created Inventory Component."));

	UE_LOG(LogTemp, Warning, TEXT("Registering delegates..."));
	OnPlayerDeath.AddUniqueDynamic(this, &AMyPlayerState::ProcessPlayerDeath);
	OnPlayerDeath.AddUniqueDynamic(this, &AMyPlayerState::ProcessPlayerRetire);
	UE_LOG(LogTemp, Warning, TEXT("Registered delegates."));
}

UInventoryComponent* AMyPlayerState::GetInventoryComponent() const
{
	if (!ensure(InventoryComponent)) { return nullptr; }

	return InventoryComponent;
}

void AMyPlayerState::SellItem(UInventoryItem* ItemToSell, float AngerMultiplier)
{
	if (!ensure(InventoryComponent) || !ensure(ItemToSell)) { return; }

	UE_LOG(LogTemp, Warning, TEXT("Passed Anger Multiplier: %f"), AngerMultiplier);

	auto AddedDeathChance = ItemToSell->GetDeathChance() * AngerMultiplier;
	UE_LOG(LogTemp, Warning, TEXT("Added Death Chance: %f"), AddedDeathChance);

	CurrentDeathChance += AddedDeathChance;
	UE_LOG(LogTemp, Warning, TEXT("Current Death Chance: %f"), CurrentDeathChance);

	CurrentMoney += InventoryComponent->SellItem(ItemToSell);
	UE_LOG(LogTemp, Warning, TEXT("Current Money: %f"), CurrentMoney);
	
	auto DeathRoll = FMath::RandRange(0.f, 1.f);
	UE_LOG(LogTemp, Warning, TEXT("Death Roll: Rolled %f, Chance was %f."), DeathRoll, CurrentDeathChance);
	if (DeathRoll < CurrentDeathChance)
	{
		IsPlayerDeadOrRetired = true;
		OnPlayerDeath.Broadcast();
		UE_LOG(LogTemp, Warning, TEXT("Player died."));
	}

	UE_LOG(LogTemp, Warning, TEXT("Player sold item."));
}

void AMyPlayerState::Retire()
{
	IsPlayerDeadOrRetired = true;
	UE_LOG(LogTemp, Warning, TEXT("Player retired."));
	OnPlayerRetire.Broadcast();
}

void AMyPlayerState::Reset()
{
	UE_LOG(LogTemp, Warning, TEXT("Reset called."));
	CurrentDeathChance = 0.0;
	CurrentMoney = 0;
}

void AMyPlayerState::LoseMoney(int32 MoneyLost)
{
	CurrentMoney -= MoneyLost;
}

//bool AMyPlayerState::IsPlayerDeadOrRetired()
//{
//	return IsPlayerDeadOrRetired;
//}
//
//void AMyPlayerState::SetIsPlayerDeadOrRetired(bool newValue)
//{
//	IsPlayerDeadOrRetired = newValue;
//}