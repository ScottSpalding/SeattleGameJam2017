// Fill out your copyright notice in the Description page of Project Settings.

#include "InventoryRandomizer.h"

#include "InventoryItem.h"

UInventoryItem* UInventoryRandomizer::GetNewItem()
{
	auto NewItem = NewObject<UInventoryItem>();

	//auto ItemIndex = FMath::RandRange(0, 2); // remember this is 0-max inclusive, so max should be the total number of items - 1

	return NewItem;
}

TArray<UInventoryItem*> UInventoryRandomizer::GetAllInventoryItems()
{
	return InventoryItems;
}

void UInventoryRandomizer::CreateInventoryItems()
{
	UE_LOG(LogTemp, Warning, TEXT("Created Inventory Items, should only happen once!"));

	auto IIBoxOfRocks = NewObject<UInventoryItem>();
	IIBoxOfRocks->Initialize("Box of Rocks", 3, 3, .03);
	InventoryItems.Add(IIBoxOfRocks);

	auto IIJarOfMagicBeans = NewObject<UInventoryItem>();
	IIJarOfMagicBeans->Initialize("Jar Of Magic Beans", 4, 4, .04);
	InventoryItems.Add(IIJarOfMagicBeans);

	auto IIIdiopathfinder = NewObject<UInventoryItem>();
	IIIdiopathfinder->Initialize("Idiopathfinder", 5, 5, .05);
	InventoryItems.Add(IIIdiopathfinder);

	//InventoryItems.Add(UInventoryItem("Box of Rocks", 3, 3, .03));
	//InventoryItems.Add(UInventoryItem("Jar Of Magic Beans", 4, 4, .04));
	//InventoryItems.Add(UInventoryItem("Idiopathfinder", 5, 5, .05));
}

