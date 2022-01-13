
#include "YH/Utilites/YH_CLog.h"
#include "Engine.h"

DEFINE_LOG_CATEGORY_STATIC(GameProject, Display, All)

void YH_CLog::Print(int32 InValue, int32 InKey, float Duration, FColor InColor)
{
	GEngine->AddOnScreenDebugMessage(InKey, Duration, InColor, FString::FromInt(InValue));
}

void YH_CLog::Print(float InValue, int32 InKey, float Duration, FColor InColor)
{
	GEngine->AddOnScreenDebugMessage(InKey, Duration, InColor, FString::SanitizeFloat(InValue));
}

void YH_CLog::Print(const FString& InValue, int32 InKey, float Duration, FColor InColor)
{
	GEngine->AddOnScreenDebugMessage(InKey, Duration, InColor, InValue);
}

void YH_CLog::Print(const FVector& InValue, int32 InKey, float Duration, FColor InColor)
{
	GEngine->AddOnScreenDebugMessage(InKey, Duration, InColor, InValue.ToString());
}

void YH_CLog::Print(const FRotator& InValue, int32 InKey, float Duration, FColor InColor)
{
	GEngine->AddOnScreenDebugMessage(InKey, Duration, InColor, InValue.ToString());
}

void YH_CLog::Log(int32 InValue)
{
	UE_LOG(GameProject, Display, L"%d", InValue);
}

void YH_CLog::Log(float InValue)
{
	UE_LOG(GameProject, Display, L"%f", InValue);
}

void YH_CLog::Log(const FString& InValue)
{
	UE_LOG(GameProject, Display, L"%s", *InValue);
}

void YH_CLog::Log(const FVector& InValue)
{
	UE_LOG(GameProject, Display, L"%s", *InValue.ToString());
}

void YH_CLog::Log(const FRotator& InValue)
{
	UE_LOG(GameProject, Display, L"%s", *InValue.ToString());
}

void YH_CLog::Log(const UObject* InObject)
{
	FString str;
	if (!!InObject)
		str.Append(InObject->GetName());

	str.Append(!!InObject ? " Not Null" : "Null");

	UE_LOG(GameProject, Display, L"%s", *str);
}

void YH_CLog::Log(const FString& InFuncName, int32 InLineNumber)
{
	FString str;
	str.Append(InFuncName);
	str.Append(", ");
	str.Append(FString::FromInt(InLineNumber));

	UE_LOG(GameProject, Display, L"%s", *str);
}
