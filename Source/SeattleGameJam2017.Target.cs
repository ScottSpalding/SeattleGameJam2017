// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class SeattleGameJam2017Target : TargetRules
{
	public SeattleGameJam2017Target(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;

		ExtraModuleNames.AddRange( new string[] { "SeattleGameJam2017" } );
	}
}
