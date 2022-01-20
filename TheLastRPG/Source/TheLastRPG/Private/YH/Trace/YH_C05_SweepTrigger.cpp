#include "YH/Trace/YH_C05_SweepTrigger.h"
#include "YH/Trace/YH_C04_Explosion.h"
#include "YH/Global_YH.h"
#include "Components/BoxComponent.h"
#include "Components/TextRenderComponent.h"

AYH_C05_SweepTrigger::AYH_C05_SweepTrigger()
{
	CHelpers_YH::CreateComponent<USceneComponent>(this, &Scene, "Scene");
	CHelpers_YH::CreateComponent<UBoxComponent>(this, &Box, "Box", Scene);
	CHelpers_YH::CreateComponent<UTextRenderComponent>(this, &Text, "Text", Scene);


	Box->SetRelativeScale3D(FVector(3));
	Box->bHiddenInGame = false;

	Text->SetRelativeLocation(FVector(0, 0, 100));
	Text->SetRelativeRotation(FRotator(0, 180, 0));
	Text->SetRelativeScale3D(FVector(2));
	Text->TextRenderColor = FColor::Red;
	Text->HorizontalAlignment = EHorizTextAligment::EHTA_Center;
	Text->Text = FText::FromString(GetName());

}

// Called when the game starts or when spawned
void AYH_C05_SweepTrigger::BeginPlay()
{
	Super::BeginPlay();
	TArray<AYH_C04_Explosion*> explosions;
	CHelpers_YH::FindActors(GetWorld(), explosions);
	//이걸로 델리게이트 선언안해줘도 그냥 바로 델리게이트로 붙는다.(외부에서 콜)
	OnActorBeginOverlap.AddDynamic(explosions[0], &AYH_C04_Explosion::ActorBeginOverlap);
}



