// Fill out your copyright notice in the Description page of Project Settings.

#include "InventoryComponent.h"

#include "InventoryRandomizer.h"
#include "InventoryItem.h"

// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	UE_LOG(LogTemp, Warning, TEXT("Created Inventory Component."));

	Randomizer = NewObject<UInventoryRandomizer>();
	if ( !ensure(Randomizer) ) { return; }
	Randomizer->CreateInventoryItems();

	/*for (int32 index = 0; index < DefaultInventorySize; index++) {
		Items.Add(Randomizer->GetNewItem());
	}*/
	Items = Randomizer->GetAllInventoryItems();
}


int32 UInventoryComponent::GetSelectedInventoryItem()
{
	return SelectedInventoryItem;
}

void UInventoryComponent::SetSelectedInventoryItem(int32 NewSelectedInventoryItem)
{
	SelectedInventoryItem = NewSelectedInventoryItem;
}

TArray<UInventoryItem*> UInventoryComponent::GetItems() const
{
	return Items;
}

int32 UInventoryComponent::SellItem(UInventoryItem* ItemToSell)
{
	if (!ensure(ItemToSell)) { return 0; }
	auto CurrentPrice = ItemToSell->GetCurrentPrice();
	UE_LOG(LogTemp, Warning, TEXT("Inventory items size is:%i"), Items.Num());
	//Items.Remove(ItemToSell);
	return CurrentPrice;
}

