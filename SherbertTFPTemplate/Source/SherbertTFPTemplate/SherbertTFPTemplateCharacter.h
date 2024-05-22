// ©2024 JDSherbert. All rights reserved.

#pragma once

#include <CoreMinimal.h>

#include <GameFramework/Character.h>
#include <Logging/LogMacros.h>

#include "SherbertTFPTemplateCharacter.generated.h"

/* ------------------------------------------------------------ */

class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

/* ------------------------------------------------------------ */

DECLARE_LOG_CATEGORY_EXTERN(LogTemplateCharacter, Log, All);

/* ------------------------------------------------------------ */

UCLASS(config=Game)
class ASherbertTFPTemplateCharacter : public ACharacter
{
	GENERATED_BODY()

	/** True First Person camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* TrueFirstPersonCamera;
	
	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputMappingContext* DefaultMappingContext;

	/** Jump Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* JumpAction;

	/** Move Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* MoveAction;

	/** Look Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* LookAction;

public:

	ASherbertTFPTemplateCharacter();
	

protected:

	/** Called for movement input */
	void Move(const FInputActionValue& Value);

	/** Called for looking input */
	void Look(const FInputActionValue& Value);
			

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	// To add mapping context
	virtual void BeginPlay();

public:

	/** Returns TrueFirstPersonCamera subobject **/
	FORCEINLINE class UCameraComponent* GetTrueFirstPersonCamera() const 
	{ return TrueFirstPersonCamera; }
};

/* ------------------------------------------------------------ */

