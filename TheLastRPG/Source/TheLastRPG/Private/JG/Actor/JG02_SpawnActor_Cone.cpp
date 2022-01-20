// Fill out your copyright notice in the Description page of Project Settings.


#include "JG/Actor/JG02_SpawnActor_Cone.h"
#include "JG/JG_Global.h"

AJG02_SpawnActor_Cone::AJG02_SpawnActor_Cone()
{
	UStaticMesh* mesh;
	JG_Helpers::GetAsset<UStaticMesh>(&mesh, "StaticMesh'/Game/JongGyun/Meshs/M_Cone.M_Cone'");
	Mesh->SetStaticMesh(mesh);
}