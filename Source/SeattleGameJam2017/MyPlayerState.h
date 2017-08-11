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
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void Initialize();

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	UInventoryComponent* GetInventoryComponent() const;

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void SellItem(UInventoryItem* ItemToSell, float AngerMultiplier, float CustomerUpsoldRating);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void Retire();

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void Reset();

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void LoseMoney(int32 MoneyLost);

	FMyPlayerStateDelegate OnPlayerDeath;

	FMyPlayerStateDelegate OnPlayerLoseMoney;

	FMyPlayerStateDelegate OnPlayerRetire;

	UFUNCTION(BlueprintImplementableEvent, Category = "Inventory")
	void ProcessPlayerRetire();

	UFUNCTION(BlueprintImplementableEvent, Category = "Inventory")
	void ProcessPlayerDeath();
	
protected:

	UPROPERTY(BlueprintReadOnly, Category = "Inventory")
	bool IsPlayerDeadOrRetired = false;

	UPROPERTY(BlueprintReadOnly, Category = "Inventory")
	int32 CurrentMoney = 0;

	UPROPERTY(BlueprintReadOnly, Category = "Inventory")
	float CurrentDeathChance = 0.f;

	UPROPERTY(BlueprintReadOnly, Category = "Inventory")
	UInventoryComponent* InventoryComponent = nullptr;
};
