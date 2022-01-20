// Fill out your copyright notice in the Description page of Project Settings.
#include "YH/Global_YH.h"
#include "Components/StaticMeshComponent.h"
#include "YH/Trace/YH_C03_Cube.h"

// Sets default values
AYH_C03_Cube::AYH_C03_Cube()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	CHelpers_YH::CreateComponent<UStaticMeshComponent>(this, &Mesh, "Mesh");

	UStaticMesh* mesh;
	CHelpers_YH::GetAsset<UStaticMesh>(&mesh,"StaticMesh'/Game/YongHwan/Meshes/YH_Cube.YH_Cube'");
	Mesh->SetStaticMesh(mesh);
	Mesh->SetSimulatePhysics(true);
	//콜리전채널 지정할수 있다. 엔진 트레이스 채널이 있고(우리안사용), 거의 게임채널사용한다(1번부터 시작한다)-5로 되어있자나
	Mesh->SetCollisionObjectType(ECollisionChannel::ECC_PhysicsBody);

}

// Called when the game starts or when spawned
void AYH_C03_Cube::BeginPlay()
{
	Super::BeginPlay();

	
}



