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

	int32 PreferredConType = FMath::RandRange(0, 2);
	UE_LOG(LogTemp, Warning, TEXT("Preferred Con Type Roll: %i"), PreferredConType);
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

	SetCustomerAngerRating(1);
	SetCustomerUpsoldRating(1);
	SetIsAngryFromLastRound(false);
	SetIsUpsoldFromLastRound(false);
}

bool UCustomer::ProcessConTactic(EConTactic UsedConTactic) 
{
	bool CustomerLeaving = false;
	if (UsedConTactic == PreferredConTactic)
	{
		SetCustomerAngerRating(GetCustomerAngerRating() - .33);
		SetCustomerUpsoldRating(GetCustomerUpsoldRating() + 1);
		UE_LOG(LogTemp, Warning, TEXT("Upsold!"));
		UE_LOG(LogTemp, Warning, TEXT("GetCustomerUpsoldRating: %f"), GetCustomerUpsoldRating());
		SetIsAngryFromLastRound(false);
		SetIsUpsoldFromLastRound(true);
	} else if (UsedConTactic == HatedConTactic)
	{
		SetCustomerAngerRating(GetCustomerAngerRating() + 1);
		SetCustomerUpsoldRating(GetCustomerUpsoldRating() - .33);
		auto LeaveRoll = FMath::RandRange(0.f, 1.f);
		UE_LOG(LogTemp, Warning, TEXT("LeaveRoll (compared to .333): %f"), LeaveRoll);
		CustomerLeaving = LeaveRoll < .333;
		SetIsAngryFromLastRound(true);
		SetIsUpsoldFromLastRound(false);
	}
	return CustomerLeaving;
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

float UCustomer::GetCustomerUpsoldRating()
{
	return CustomerUpsoldRating;
}

void UCustomer::SetCustomerUpsoldRating(float NewCustomerUpsoldRating)
{
	CustomerUpsoldRating = NewCustomerUpsoldRating;
}

bool UCustomer::GetIsAngryFromLastRound()
{
	return IsAngryFromLastRound;
}

void UCustomer::SetIsAngryFromLastRound(bool NewIsAngryFromLastRound)
{
	IsAngryFromLastRound = NewIsAngryFromLastRound;
}

bool UCustomer::GetIsUpsoldFromLastRound()
{
	return IsUpsoldFromLastRound;
}

void UCustomer::SetIsUpsoldFromLastRound(bool NewIsUpsoldFromLastRound)
{
	IsUpsoldFromLastRound = NewIsUpsoldFromLastRound;
}
