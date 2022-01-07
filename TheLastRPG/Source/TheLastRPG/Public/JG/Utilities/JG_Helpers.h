#pragma once

#include "UObject/ConstructorHelpers.h"

class THELASTRPG_API JG_Helpers
{
public:
	template<typename T>
	static void GetAsset(T** OutObject, FString InPath)
	{
		ConstructorHelpers::FObjectFinder<T> asset(*InPath);
		verify(asset.Succeeded(), "asset.Succeeded()");
		*OutObject = asset.Object;
	}
};