// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class TheLastRPG : ModuleRules
{
	public TheLastRPG(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });

        PublicIncludePaths.Add(ModuleDirectory);
    }
}
