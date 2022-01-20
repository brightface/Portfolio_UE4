#include "YH/Collision/YH_C06_Box.h"
#include "YH/Global_YH.h"
#include "YH/Collision/YH_C05_MulticastTrigger.h"
#include "Components/TextRenderComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/MaterialInstanceConstant.h"
#include "Materials/MaterialInstanceDynamic.h"

//박스에서 한번 에러남
AYH_C06_Box::AYH_C06_Box()
{
	CHelpers_YH::CreateComponent<USceneComponent>(this, &Scene, "Scene");
	CHelpers_YH::CreateComponent<UTextRenderComponent>(this, &Text, "Text", Scene);

	Text->SetRelativeLocation(FVector(0, 0, 100));
	Text->SetRelativeRotation(FRotator(0, 180, 0));
	Text->SetRelativeScale3D(FVector(2));
	Text->TextRenderColor = FColor::Red;
	Text->HorizontalAlignment = EHorizTextAligment::EHTA_Center;
	Text->Text = FText::FromString(GetName());


	UStaticMesh* mesh;
	CHelpers_YH::GetAsset<UStaticMesh>(&mesh, "StaticMesh'/Game/YongHwan/Meshes/YH_Cube.YH_Cube'");
	for (int32 i = 0; i < 3; i++)
	{
		FString str;
		str.Append("Mesh_");
		str.Append(FString::FromInt(i + 1));

		CHelpers_YH::CreateComponent<UStaticMeshComponent>(this, &Mesh[i], FName(str), Scene);

		Mesh[i]->SetRelativeLocation(FVector(0, i * 150, 0));
		Mesh[i]->SetStaticMesh(mesh);
		Mesh[i]->SetSimulatePhysics(false);
	}

}

void AYH_C06_Box::BeginPlay()
{
	Super::BeginPlay();

	TArray<AYH_C05_MulticastTrigger *> triggers;
	CHelpers_YH::FindActors<AYH_C05_MulticastTrigger>(GetWorld(), triggers);
	
	//이거때문에 터진다. - 이게 무엇인가 잘 알 필요가 있다.
	//triggers[0]->OnMultiLightBeginOverlap.AddUFunction(this, "OnPhysics");

	//MaterialInstanceConstant'/Game/YongHwan/Materials/YH_Mesh_Inst.YH_Mesh_Inst'
	UMaterialInstanceConstant* material;
	CHelpers_YH::GetAssetDynamic<UMaterialInstanceConstant>(&material, "MaterialInstanceConstant'/Game/YongHwan/Materials/YH_Mesh_Inst.YH_Mesh_Inst'");

	for (int32 i = 0; i < 3; i++)
	{
		Materials[i] = UMaterialInstanceDynamic::Create(material, this);
		Mesh[i]->SetMaterial(0, Materials[i]);

		FTransform transform = Mesh[i]->GetComponentToWorld();
		WorldLocation[i] = transform.GetLocation();
	}
}

void AYH_C06_Box::OnPhysics(int32 InIndex, FLinearColor InColor)
{
	for (int32 i = 0; i < 3; i++)
	{
		Materials[i]->SetVectorParameterValue("Color", FLinearColor(1, 1, 1));

		Mesh[i]->SetSimulatePhysics(false);
		Mesh[i]->SetWorldLocation(WorldLocation[i]);
	}

	Materials[InIndex]->SetVectorParameterValue("Color", InColor);
	Mesh[InIndex]->SetSimulatePhysics(true);
}
