// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "InventoryItem.generated.h"

/**
 * 
 */
UCLASS()
class SEATTLEGAMEJAM2017_API UInventoryItem : public UDataAsset
{
	GENERATED_BODY()

public:
	UInventoryItem();

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void Initialize(FString NewName, int32 NewBasePrice, int32 NewCurrentPrice, float NewDeathChance);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	FString GetName() const;

	void SetName(FString NewName);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	int32 GetBasePrice() const;

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	int32 GetCurrentPrice() const;

	void SetCurrentPrice(int32 NewPrice);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	float GetDeathChance() const;

	void SetDeathChance(int32 NewDeathChance);

private:
	FString Name = "Default Name";
	
	int32 BasePrice = 1;

	int32 CurrentPrice = 1;

	float DeathChance = 0.f;
};
