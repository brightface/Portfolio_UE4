#include "YH/Collision/YH_C10_Override.h"
#include "YH/Global_YH.h"
#include "YH/CPlayer_YH.h"
#include "Components/BoxComponent.h"
#include "Components/TextRenderComponent.h"

AYH_C10_Override::AYH_C10_Override()
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

void AYH_C10_Override::BeginPlay()
{
	Super::BeginPlay();
	OnActorBeginOverlap.AddDynamic(this, &AYH_C10_Override::ActorBeginOverlap);
	OnActorEndOverlap.AddDynamic(this, &AYH_C10_Override::ActorEndOverlap);
}

//void AYH_C10_Override::ChangeColorRed()
//{
//	
//}
//
//void AYH_C10_Override::ChangeColorWhite()
//{
//	
//}

void AYH_C10_Override::ChangeColorWhite_Implementation()
{
	ACPlayer_YH* player = Cast<ACPlayer_YH>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	player->ChangeColor(FLinearColor(0, 0, 1));
}

void AYH_C10_Override::ActorBeginOverlap(AActor * OverlappedActor, AActor * OtherActor)
{
	ChangeColorRed();
}

void AYH_C10_Override::ActorEndOverlap(AActor * OverlappedActor, AActor * OtherActor)
{
	ChangeColorWhite();
}


