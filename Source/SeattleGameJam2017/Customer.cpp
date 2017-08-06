// Fill out your copyright notice in the Description page of Project Settings.

#include "Customer.h"

void UCustomer::Initialize()
{

}

void UCustomer::ProcessConTactic(EConTactic UsedConTactic) 
{

}

EConTactic UCustomer::GetPreferredConTactic() 
{
	return PreferredConTactic;
}

void UCustomer::SetPreferredConTactic(EConTactic NewPreferredConTactic) 
{
	PreferredConTactic = NewPreferredConTactic;
}

int32 UCustomer::GetCustomerNumber()
{
	return CustomerNumber;
}

void UCustomer::SetCustomerNumber(int32 NewCustomerNumber)
{
	CustomerNumber = NewCustomerNumber;
}

float UCustomer::GetCustomerAngerRating()
{
	return CustomerAngerRating;
}

void UCustomer::SetCustomerAngerRating(float NewCustomerAngerRating)
{
	CustomerAngerRating = NewCustomerAngerRating;
}