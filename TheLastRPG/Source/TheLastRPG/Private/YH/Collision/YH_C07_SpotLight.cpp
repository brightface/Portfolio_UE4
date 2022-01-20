#include "YH/Collision/YH_C07_SpotLight.h"
#include "YH/Global_YH.h"
#include "YH/Collision/YH_C05_MulticastTrigger.h"
#include "Components/TextRenderComponent.h"
#include "Components/SpotLightComponent.h"


AYH_C07_SpotLight::AYH_C07_SpotLight()
{
	CHelpers_YH::CreateComponent<USceneComponent>(this, &Scene, "Scene");
	CHelpers_YH::CreateComponent<UTextRenderComponent>(this, &Text, "Text", Scene);

	Text->SetRelativeLocation(FVector(0, 0, 100));
	Text->SetRelativeRotation(FRotator(0, 180, 0));
	Text->SetRelativeScale3D(FVector(2));
	Text->TextRenderColor = FColor::Red;
	Text->HorizontalAlignment = EHorizTextAligment::EHTA_Center;
	Text->Text = FText::FromString(GetName());

	for (int32 i = 0; i < 3; i++)
	{
		FString str;
		str.Append("SpotLights_");
		str.Append(FString::FromInt(i + 1));

		CHelpers_YH::CreateComponent<USpotLightComponent>(this, &SpotLights[i], FName(str), Scene);

		SpotLights[i]->SetRelativeLocation(FVector(0, i * 150, 0));
		SpotLights[i]->SetRelativeRotation(FRotator(-90, 0, 0));
		SpotLights[i]->Intensity = 1e+5f;
		SpotLights[i]->OuterConeAngle = 25.0f;
	}
}

// Called when the game starts or when spawned
void AYH_C07_SpotLight::BeginPlay()
{
	Super::BeginPlay();
	TArray<AYH_C05_MulticastTrigger*> triggers;
	CHelpers_YH::FindActors<AYH_C05_MulticastTrigger>(GetWorld(), triggers);
	
	//왜 이거 넣으면 터지지?
	//triggers[0]->OnMultiLightBeginOverlap.AddUFunction(this, "OnLightColor");
	
	//if (triggers[0]->OnMultiLightBeginOverlap.IsBound())
	//	triggers[0]->OnMultiLightBeginOverlap.Broadcast(0, FLinearColor(0, 0, 1));
}

void AYH_C07_SpotLight::OnLightColor(int32 InIndex, FLinearColor InColor)
{
	for (int32 i = 0; i < 3; i++)
		SpotLights[i]->SetLightColor(FLinearColor(1, 1, 1));

	SpotLights[InIndex]->SetLightColor(InColor);
}


