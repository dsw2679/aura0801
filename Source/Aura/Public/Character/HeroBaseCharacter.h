// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/BaseCharacter.h"
#include "HeroBaseCharacter.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API AHeroBaseCharacter : public ABaseCharacter
{
	GENERATED_BODY()	

public:
	AHeroBaseCharacter();

	virtual void Tick(float DeltaSeconds) override;

	FORCEINLINE class UCameraComponent* GetTopDownCameraComponent() const { return TopDownCameraComponent; }	
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }

private:	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* TopDownCameraComponent;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;
};
