// Fill out your copyright notice in the Description page of Project Settings.

#include "InventoryRandomizer.h"

#include "InventoryItem.h"

UInventoryItem* UInventoryRandomizer::GetNewItem()
{
	auto newItem = NewObject<UInventoryItem>();
	newItem->SetName("dummy");
	return newItem;
}

