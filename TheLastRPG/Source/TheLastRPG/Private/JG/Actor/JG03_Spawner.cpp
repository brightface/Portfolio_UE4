#include "JG/Actor/JG03_Spawner.h"
#include "JG/JG_Global.h"
#include "JG/Actor/JG02_SpawnActor.h"

AJG03_Spawner::AJG03_Spawner()
{

}

void AJG03_Spawner::BeginPlay()
{
	Super::BeginPlay();
	
	for (int32 i = 0; i < 3; i++)
	{
		FTransform transform;
		FVector location = GetActorLocation();

		// (1) 등장 시키면서 바로 위치 저장 (등장하고 위치 세팅 이후에 다른업무 처리할 때)
		transform.SetLocation(FVector(location.X + i * 400, location.Y, location.Z));
		SpawnActors[i] = GetWorld()->SpawnActor<AJG02_SpawnActor>(SpawnClass[i], transform);

		// (2) 등장 시킨 다음 위치 저장 (등장과 동시에 다른 업무를 처리할 때)
		//SpawnActors[i]->SetActorLocation(FVector(location.X + i * 400, location.Y, location.Z));
	}
}

