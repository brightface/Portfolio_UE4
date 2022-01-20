// Fill out your copyright notice in the Description page of Project Settings.


#include "JG/Collision/JG06_Box.h"
#include "JG/Collision/JG05_MulticastTrigger.h"
#include "JG/JG_Global.h"
#include "Components/TextRenderComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/MaterialInstanceConstant.h"
#include "Materials/MaterialInstanceDynamic.h"

// Sets default values
AJG06_Box::AJG06_Box()
{
	JG_Helpers::CreateComponent<USceneComponent>(this, &Scene, "Scene");
	
	JG_Helpers::CreateComponent<UTextRenderComponent>(this, &Text, "Text", Scene);

	Text->SetRelativeLocation(FVector(0, 0, 100));
	Text->SetRelativeRotation(FRotator(0, 180, 0));
	Text->SetRelativeScale3D(FVector(2));
	Text->TextRenderColor = FColor::Red;
	Text->HorizontalAlignment = EHorizTextAligment::EHTA_Center;
	Text->Text = FText::FromString(GetName());


	UStaticMesh* mesh;
	JG_Helpers::GetAsset<UStaticMesh>(&mesh, "StaticMesh'/Game/JongGyun/Meshs/M_Cube.M_Cube'");
	for (int32 i = 0; i < 3; ++i)
	{
		FString str;
		str.Append("Mesh_");
		str.Append(FString::FromInt(i + 1));

		JG_Helpers::CreateComponent<UStaticMeshComponent>(this, &Mesh[i], FName(str), Scene);
		Mesh[i]->SetRelativeLocation(FVector(0, i * 150, 0));
		Mesh[i]->SetStaticMesh(mesh);
		Mesh[i]->SetSimulatePhysics(false);
	}
}

// Called when the game starts or when spawned
void AJG06_Box::BeginPlay()
{
	Super::BeginPlay();
	
	TArray<AJG05_MulticastTrigger*> triggers;
	JG_Helpers::FindActors<AJG05_MulticastTrigger>(GetWorld(), triggers);

	triggers[0]->OnMultiLightBeginOverlap.AddUFunction(this, "OnPhysics"); 

	UMaterialInstanceConstant* material;
	JG_Helpers::GetAssetDynamic<UMaterialInstanceConstant>(&material, "MaterialInstanceConstant'/Game/SungHoon/Materials/M_Mesh_Inst.M_Mesh_Inst'");

	for (int32 i = 0; i < 3; ++i)
	{
		Materials[i] = UMaterialInstanceDynamic::Create(material, this);
		Mesh[i]->SetMaterial(0, Materials[i]);

		FTransform transform = Mesh[i]->GetComponentToWorld(); 
		WorldLocation[i] = transform.GetLocation(); 
	}
}

void AJG06_Box::OnPhysics(int32 InIndex, FLinearColor InColor)
{
	for (int32 i = 0; i < 3; ++i)
	{
		Materials[i]->SetVectorParameterValue("Color", FLinearColor(1, 1, 1));

		Mesh[i]->SetSimulatePhysics(false);
		Mesh[i]->SetWorldLocation(WorldLocation[i]); // 이동한 다음 위치도 기억해놓고 있기 때문에 위치 초기화가 안됨( = 제자리에서 색만바뀌는 경우)
	}

	Materials[InIndex]->SetVectorParameterValue("Color", InColor);
	Mesh[InIndex]->SetSimulatePhysics(true);
}