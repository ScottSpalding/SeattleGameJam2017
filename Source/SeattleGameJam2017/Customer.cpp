// Fill out your copyright notice in the Description page of Project Settings.

#include "Customer.h"

void UCustomer::Initialize()
{
	auto RandomCustomerType = FMath::RandRange(0, 1);
	switch (RandomCustomerType)
	{
		case (0):
			SetCustomerType(ECustomerType::Raider);
			break;
		case (1):
			SetCustomerType(ECustomerType::Mutant);
			break;
	}

	auto PreferredConType = FMath::RandRange(0, 2);
	switch (RandomCustomerType)
	{
		case (0):
			SetPreferredConTactic(EConTactic::SweetTalk);
			SetHatedConTactic(EConTactic::Insult);
			break;
		case (1):
			SetPreferredConTactic(EConTactic::Insult);
			SetHatedConTactic(EConTactic::Upsell);
			break;
		case (2):
			SetPreferredConTactic(EConTactic::Upsell);
			SetHatedConTactic(EConTactic::SweetTalk);
			break;
	}

	SetCustomerAngerRating(.03);
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

EConTactic UCustomer::GetHatedConTactic()
{
	return HatedConTactic;
}

void UCustomer::SetHatedConTactic(EConTactic NewHatedConTactic)
{
	HatedConTactic = NewHatedConTactic;
}

ECustomerType UCustomer::GetCustomerType()
{
	return CustomerType;
}

void UCustomer::SetCustomerType(ECustomerType NewCustomerType)
{
	CustomerType = NewCustomerType;
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