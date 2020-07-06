// Copyright Octavian Rusu 2020

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "GrabbingSystem.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UNREALDOCS_API UGrabbingSystem : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabbingSystem();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:

//Private

	FVector PlayerViewLocation;
	FRotator PlayerViewRotation;
	void Grab();
	void Release();
	void FindPhysicsHandle();
	void SetupInputComponent();

	//Return the first Actor within reach.
	FHitResult GetFirstPhysicsBodyWithinReach();

//Editable
	UPROPERTY(EditAnywhere)
	float GrabbingReach = 400.f;

//Pointers
	UPhysicsHandleComponent* PhysicsHandle = nullptr;
	UInputComponent* PlayerInput = nullptr;

};
