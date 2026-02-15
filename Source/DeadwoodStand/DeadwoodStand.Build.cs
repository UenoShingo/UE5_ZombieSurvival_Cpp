// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;

public class DeadwoodStand : ModuleRules
{
	public DeadwoodStand(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput"
		});

		PrivateDependencyModuleNames.AddRange(new string[] {
		});
	}
}
