// ©2024 JDSherbert. All rights reserved.

#include "SherbertTFPTemplateGameMode.h"

#include <UObject/ConstructorHelpers.h>

#include "SherbertTFPTemplateCharacter.h"

/* ------------------------------------------------------------ */

ASherbertTFPTemplateGameMode::ASherbertTFPTemplateGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TrueFirstPerson/Blueprints/BP_TrueFirstPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

/* ------------------------------------------------------------ */
