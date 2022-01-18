#include "SH/SH_CRifle.h"
#include "SH/SH_Global.h"
#include "Components/SkeletalMeshComponent.h"

ASH_CRifle::ASH_CRifle()
{
	PrimaryActorTick.bCanEverTick = true;

	SH_CHelpers::CreateComponent<USkeletalMeshComponent>(this, &Mesh, "Mesh");


	USkeletalMesh* mesh;
	SH_CHelpers::GetAsset<USkeletalMesh>(&mesh, "SkeletalMesh'/Game/ParagonCountess/Characters/Heroes/Countess/Meshes/SM_Countess.SM_Countess'");
	Mesh->SetSkeletalMesh(mesh);
}

void ASH_CRifle::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASH_CRifle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

