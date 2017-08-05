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

	UInventoryItem(FString NewName);

	UFUNCTION(BlueprintCallable, Category = "Traits")
	FString GetName() const;

	void SetName(FString NewName);

private:
	FString Name = "Default Name";
	
	
};
