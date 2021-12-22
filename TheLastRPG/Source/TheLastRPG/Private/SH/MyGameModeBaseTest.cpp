// Fill out your copyright notice in the Description page of Project Settings.


#include "SH/MyGameModeBaseTest.h"
#include "SH/PlayerCharacter.h"

AMyGameModeBaseTest::AMyGameModeBaseTest()
{
	DefaultPawnClass = APlayerCharacter::StaticClass();
}