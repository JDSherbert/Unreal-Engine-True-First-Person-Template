// ©2024 JDSherbert. All rights reserved.

using UnrealBuildTool;

public class SherbertTFPTemplate : ModuleRules
{
	public SherbertTFPTemplate(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
