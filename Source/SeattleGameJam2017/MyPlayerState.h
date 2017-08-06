// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "MyPlayerState.generated.h"

class UInventoryComponent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FMyPlayerStateDelegate);

/**
 * 
 */
UCLASS()
class SEATTLEGAMEJAM2017_API AMyPlayerState : public APlayerState
{
	GENERATED_BODY()

public:

	AMyPlayerState();

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	UInventoryComponent* GetInventoryComponent() const;

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void SellItem(UInventoryItem* ItemToSell);

	FMyPlayerStateDelegate OnPlayerDeath;

	FMyPlayerStateDelegate OnPlayerLoseMoney;

	UFUNCTION(BlueprintImplementableEvent, Category = "Inventory")
	void ProcessPlayerDeath();
	
protected:

	UPROPERTY(BlueprintReadOnly, Category = "Inventory")
	int32 CurrentMoney = 0;

	UPROPERTY(BlueprintReadOnly, Category = "Inventory")
	float CurrentDeathChance = 1.f;

private:

	UInventoryComponent* InventoryComponent = nullptr;
	
};
