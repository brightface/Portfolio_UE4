#include "SH/SH_CGameMode.h"
#include "SH/PlayerCharacter.h"
#include "SH/SH_Global.h"

ASH_CGameMode::ASH_CGameMode()
{
	//DefaultPawnClass = APlayerCharacter::StaticClass();
	
	/*ConstructorHelpers::FClassFinder<APawn> pawn(L"Blueprint'/Game/SungHoon/Blueprints/BP_SH_Player.BP_SH_Player_C'");
	if (pawn.Succeeded())
		DefaultPawnClass = pawn.Class;*/

	FString url = "Blueprint'/Game/SungHoon/Blueprints/BP_SH_CPlayer.BP_SH_CPlayer_C'"; // _C¡÷¿«
	SH_CHelpers::GetClass<APawn>(&DefaultPawnClass, url);
}