// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class TestCPPProject : ModuleRules
{
	public TestCPPProject(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "EnhancedInput" });
	}
}
