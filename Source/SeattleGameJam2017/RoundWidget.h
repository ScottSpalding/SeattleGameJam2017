// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "RoundWidget.generated.h"

class UCustomer;

/**
 * 
 */
UCLASS()
class SEATTLEGAMEJAM2017_API URoundWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "Customer")
	void ResetRound();

	UFUNCTION(BlueprintCallable, Category = "Customer")
	void GetNewCustomer();

	UFUNCTION(BlueprintCallable, Category = "Customer")
	int32 GetCurrentRound();
	UFUNCTION(BlueprintCallable, Category = "Customer")
	void SetCurrentRound(int32 NewCurrentRound);
	int32 CurrentRound;
	
	UFUNCTION(BlueprintCallable, Category = "Customer")
	int32 GetMaxNumberOfRounds();
	UFUNCTION(BlueprintCallable, Category = "Customer")
	void SetMaxNumberOfRounds(int32 NewMaxNumberOfRounds);
	int32 MaxNumberOfRounds;
	
	UFUNCTION(BlueprintCallable, Category = "Customer")
	UCustomer* GetCustomer();
	UFUNCTION(BlueprintCallable, Category = "Customer")
	void SetCustomer(UCustomer* NewCustomer);
	UCustomer* Customer;

	UFUNCTION(BlueprintCallable, Category = "Customer")
	TArray<UCustomer*> GetCustomers() const;
	TArray<UCustomer*> Customers;
};
