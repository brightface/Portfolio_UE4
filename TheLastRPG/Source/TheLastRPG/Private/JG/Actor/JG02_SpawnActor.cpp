
#include "JG/Actor/JG02_SpawnActor.h"
#include "Components/StaticMeshComponent.h"
// Sets default values
AJG02_SpawnActor::AJG02_SpawnActor()
{
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	RootComponent = Mesh;
	ConstructorHelpers::FObjectFinder<UStaticMesh> mesh(L"StaticMesh'/Game/JongGyun/Meshs/M_Cube.M_Cube'");
	if (mesh.Succeeded())
		Mesh->SetStaticMesh(mesh.Object);

}

// Called when the game starts or when spawned
void AJG02_SpawnActor::BeginPlay()
{
	Super::BeginPlay();
	
}


