// Fill out your copyright notice in the Description page of Project Settings.

#include "InventoryItem.h"


UInventoryItem::UInventoryItem()
{

}

void UInventoryItem::Initialize(FString NewName, int32 NewBasePrice, int32 NewCurrentPrice, float NewDeathChance)
{
	Name = NewName;
	BasePrice = NewBasePrice;
	CurrentPrice = NewCurrentPrice;
	DeathChance = NewDeathChance;
}

FString UInventoryItem::GetName() const
{
	return Name;
}

void UInventoryItem::SetName(FString NewName)
{
	Name = NewName;
}

int32 UInventoryItem::GetBasePrice() const
{
	return BasePrice;
}

int32 UInventoryItem::GetCurrentPrice() const
{
	return CurrentPrice;
}

void UInventoryItem::SetCurrentPrice(int32 NewPrice)
{
	CurrentPrice = NewPrice;

}

float UInventoryItem::GetDeathChance() const
{
	return DeathChance;
}

void UInventoryItem::SetDeathChance(int32 NewDeathChance)
{
	DeathChance = NewDeathChance;
}
