
#include "JG/Actor/JG02_SpawnActor.h"
#include "Components/StaticMeshComponent.h"
#include "JG/JG_Global.h"
#include "Materials/MaterialInstanceConstant.h"
#include "Materials/MaterialInstanceDynamic.h"

// Sets default values
AJG02_SpawnActor::AJG02_SpawnActor()
{
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	RootComponent = Mesh;

	//ConstructorHelpers::FObjectFinder<UStaticMesh> mesh(L"StaticMesh'/Game/JongGyun/Meshs/M_Cube.M_Cube'");
	//if (mesh.Succeeded())
	//	Mesh->SetStaticMesh(mesh.Object);

	UStaticMesh* mesh;
	JG_Helpers::GetAsset<UStaticMesh>(&mesh, "StaticMesh'/Game/JongGyun/Meshs/M_Cube.M_Cube'");
	Mesh->SetStaticMesh(mesh);
}

// Called when the game starts or when spawned
void AJG02_SpawnActor::BeginPlay()
{
	Super::BeginPlay();
	
	//MaterialInstanceConstant'/Game/JongGyun/Materials/M_Mesh_Inst.M_Mesh_Inst'
	//UObject* obj = StaticLoadObject(UMaterialInstanceConstant::StaticClass(), NULL, L"MaterialInstanceConstant'/Game/JongGyun/Materials/M_Mesh_Inst.M_Mesh_Inst'");
	//UMaterialInstanceConstant* material = Cast< UMaterialInstanceConstant>(obj);

	UMaterialInstanceConstant* material;
	JG_Helpers::GetAssetDynamic< UMaterialInstanceConstant>(&material, "MaterialInstanceConstant'/Game/JongGyun/Materials/M_Mesh_Inst.M_Mesh_Inst'");

	Material = UMaterialInstanceDynamic::Create(material, this);
	Mesh->SetMaterial(0, Material);

	UKismetSystemLibrary::K2_SetTimer(this, "ChangeColor", 1.0f, true);
}

void AJG02_SpawnActor::ChangeColor()
{
	FLinearColor color;
	color.R = UKismetMathLibrary::RandomFloatInRange(0, 1);
	color.G = UKismetMathLibrary::RandomFloatInRange(0, 1);
	color.B = UKismetMathLibrary::RandomFloatInRange(0, 1);
	color.A = 1.0f;

	Material->SetVectorParameterValue("Color", color);
}


