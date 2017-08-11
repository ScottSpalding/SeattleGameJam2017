// Fill out your copyright notice in the Description page of Project Settings.

#include "RoundWidget.h"

#include "Customer.h"

void URoundWidget::ResetRound()
{

}

void URoundWidget::GetNewCustomer() 
{
	auto NewCustomer = NewObject<UCustomer>();
	NewCustomer->Initialize();
	NewCustomer->AddToRoot();
	Customer = NewCustomer;
	Customers.Add(NewCustomer);
}

int32 URoundWidget::GetCurrentRound() 
{
	return CurrentRound;
}

void URoundWidget::SetCurrentRound(int32 NewCurrentRound) 
{
	CurrentRound = NewCurrentRound;
}

int32 URoundWidget::GetMaxNumberOfRounds()
{
	return MaxNumberOfRounds;
}

void URoundWidget::SetMaxNumberOfRounds(int32 NewMaxNumberOfRounds)
{
	MaxNumberOfRounds = NewMaxNumberOfRounds;
}

UCustomer* URoundWidget::GetCustomer()
{
	return Customer;
}

void URoundWidget::SetCustomer(UCustomer* NewCustomer)
{
	Customer = NewCustomer;
}

TArray<UCustomer*> URoundWidget::GetCustomers() const
{
	return Customers;
}