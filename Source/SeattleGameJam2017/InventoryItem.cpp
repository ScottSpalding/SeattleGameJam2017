// Fill out your copyright notice in the Description page of Project Settings.

#include "InventoryItem.h"


UInventoryItem::UInventoryItem()
	: Name("dummy")
{

}

UInventoryItem::UInventoryItem(FString NewName)
	: Name (NewName)
{

}

FString UInventoryItem::GetName() const
{
	return Name;
}

void UInventoryItem::SetName(FString NewName)
{
	Name = NewName;
}