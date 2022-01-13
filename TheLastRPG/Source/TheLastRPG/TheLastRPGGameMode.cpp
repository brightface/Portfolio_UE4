// Copyright Epic Games, Inc. All Rights Reserved.

#include "TheLastRPGGameMode.h"
#include "TheLastRPGCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "YH/Global_YH.h"

ATheLastRPGGameMode::ATheLastRPGGameMode()
{
	ConstructorHelpers::FClassFinder<APawn> pawn(L"Blueprint'/Game/YongHwan/BP/YH_BP_CPlayer.YH_BP_CPlayer_C'");
	if (pawn.Succeeded())
		pawn.Class;

	//// set default pawn class to our Blueprinted character
	//static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	//if (PlayerPawnBPClass.Class != NULL)
	//{
	//	DefaultPawnClass = PlayerPawnBPClass.Class;
	//}
}
