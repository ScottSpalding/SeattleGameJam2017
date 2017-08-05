// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryComponent.generated.h"

class UInventoryItem;
class UInventoryRandomizer;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SEATTLEGAMEJAM2017_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UInventoryComponent();

	UFUNCTION(BlueprintCallable, Category = "inventory")
	TArray<UInventoryItem*> GetItems() const;

private:
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	int32 DefaultInventorySize = 3;

	UInventoryRandomizer* Randomizer = nullptr;
	TArray<UInventoryItem*> Items;
};
