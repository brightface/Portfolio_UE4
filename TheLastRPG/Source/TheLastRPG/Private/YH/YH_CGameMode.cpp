// Copyright Epic Games, Inc. All Rights Reserved.

#include "YH/YH_CGameMode.h"
#include "TheLastRPGCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "YH/Global_YH.h"

AYH_CGameMode::AYH_CGameMode()
{
	ConstructorHelpers::FClassFinder<APawn> pawn(L"Blueprint'/Game/YongHwan/BP/YH_BP_CPlayer.YH_BP_CPlayer_C'");
	if (pawn.Succeeded())
	{
		DefaultPawnClass = pawn.Class; 
	}
	// set default pawn class to our Blueprinted character
	/*static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}*/
}
