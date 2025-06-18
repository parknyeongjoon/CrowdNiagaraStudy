// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class CrowdNiagara : ModuleRules
{
	public CrowdNiagara(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput",
			"StructUtils",
			"MassEntity",
			"MassCommon",
			"MassMovement",
			"MassNavigation",
			"Niagara",
			"NiagaraCore"
		});

		PrivateDependencyModuleNames.AddRange(new string[]
		{
			"RenderCore", "Renderer", "RHI", "Projects", "Niagara"
		});
		
		PublicIncludePaths.AddRange(new string[] {
			"CrowdNiagara"  // CrowdNiagara/ 경로 생략 가능
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
		
		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
