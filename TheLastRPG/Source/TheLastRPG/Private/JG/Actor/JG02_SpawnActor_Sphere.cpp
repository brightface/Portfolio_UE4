#include "JG/Actor/JG02_SpawnActor_Sphere.h"
#include "JG/JG_Global.h"

AJG02_SpawnActor_Sphere::AJG02_SpawnActor_Sphere()
{
	UStaticMesh* mesh;
	JG_Helpers::GetAsset<UStaticMesh>(&mesh, "StaticMesh'/Game/JongGyun/Meshs/M_Sphere.M_Sphere'");
	Mesh->SetStaticMesh(mesh);
}