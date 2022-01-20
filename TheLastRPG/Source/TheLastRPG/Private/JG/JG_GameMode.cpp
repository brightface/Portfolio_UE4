#include "JG/JG_GameMode.h"
#include "JG/JG_Player.h"
#include "JG/JG_Global.h"

AJG_GameMode::AJG_GameMode()
{
	//DefaultPawnClass = APlayerCharacter::StaticClass();
	
	/*ConstructorHelpers::FClassFinder<APawn> pawn(L"Blueprint'/Game/JongGyun/Character/BP_JG_Player.BP_JG_Player_C'");
	if (pawn.Succeeded())
		DefaultPawnClass = pawn.Class;*/

	FString url = "Blueprint'/Game/JongGyun/Character/BP_JG_Player.BP_JG_Player_C'";
	JG_Helpers::GetClass<APawn>(&DefaultPawnClass, url);
}