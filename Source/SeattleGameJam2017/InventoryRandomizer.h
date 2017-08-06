// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "InventoryRandomizer.generated.h"

class UInventoryItem;

/**
 * 
 */
UCLASS()
class SEATTLEGAMEJAM2017_API UInventoryRandomizer : public UFactory
{
	GENERATED_BODY()
	
public:	
	UInventoryItem* GetNewItem();

	TArray<UInventoryItem*> GetAllInventoryItems();

	void CreateInventoryItems();

private:
	TArray<UInventoryItem*> InventoryItems;
};
