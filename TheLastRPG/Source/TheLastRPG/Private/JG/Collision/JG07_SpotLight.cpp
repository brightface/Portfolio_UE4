// Fill out your copyright notice in the Description page of Project Settings.


#include "JG/Collision/JG07_SpotLight.h"
#include "JG/Collision/JG05_MulticastTrigger.h"
#include "JG/JG_Global.h"
#include "Components/TextRenderComponent.h"
#include "Components/SpotLightComponent.h"
// Sets default values
AJG07_SpotLight::AJG07_SpotLight()
{
	JG_Helpers::CreateComponent<USceneComponent>(this, &Scene, "Scene");
	JG_Helpers::CreateComponent<UTextRenderComponent>(this, &Text, "Text", Scene);

	Text->SetRelativeLocation(FVector(0, 0, 100));
	Text->SetRelativeRotation(FRotator(0, 180, 0));
	Text->SetRelativeScale3D(FVector(2));
	Text->TextRenderColor = FColor::Red;
	Text->HorizontalAlignment = EHorizTextAligment::EHTA_Center;
	Text->Text = FText::FromString(GetName());


	for (int32 i = 0; i < 3; ++i)
	{
		FString str;
		str.Append("SpotLights_");
		str.Append(FString::FromInt(i + 1));

		JG_Helpers::CreateComponent<USpotLightComponent>(this, &SpotLights[i], FName(str), Scene);

		SpotLights[i]->SetRelativeLocation(FVector(0, i * 150, 0));
		SpotLights[i]->SetRelativeRotation(FRotator(-90, 0, 0)); 
		SpotLights[i]->Intensity = 1e+5f;
		SpotLights[i]->OuterConeAngle = 25.0f;

	}
}

// Called when the game starts or when spawned
void AJG07_SpotLight::BeginPlay()
{
	Super::BeginPlay();

	TArray<AJG05_MulticastTrigger*> triggers;
	JG_Helpers::FindActors<AJG05_MulticastTrigger>(GetWorld(), triggers);

	triggers[0]->OnMultiLightBeginOverlap.AddUFunction(this, "OnLightColor");

	if (triggers[0]->OnMultiLightBeginOverlap.IsBound()) // 외부 연결 검사 후 콜
		triggers[0]->OnMultiLightBeginOverlap.Broadcast(0, FLinearColor(0, 0, 1));
}

void AJG07_SpotLight::OnLightColor(int32 InIndex, FLinearColor InColor)
{
	for (int32 i = 0; i < 3; ++i)
		SpotLights[i]->SetLightColor(FLinearColor(1, 1, 1));

	SpotLights[InIndex]->SetLightColor(InColor);
}