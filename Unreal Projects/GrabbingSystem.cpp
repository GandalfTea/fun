// Copyright Octavian Rusu 2020

#include "GrabbingSystem.h"
#include "DrawDebugHelpers.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"

#define OUT //for readibility, macro define. Does nothing.



// Sets default values for this component's properties
UGrabbingSystem::UGrabbingSystem()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

}


// Called when the game starts
void UGrabbingSystem::BeginPlay()
{
	Super::BeginPlay();

	FindPhysicsHandle();
	SetupInputComponent();
}


//Functions


void UGrabbingSystem::Grab()
{
	UE_LOG(LogTemp, Warning, TEXT("Grabbing button pressed."));

	FHitResult HitResult = GetFirstPhysicsBodyWithinReach();
	UPrimitiveComponent* ComponentToGrab = HitResult.GetComponent();

	FRotator Rotate(0.f, 0.f, 0.f);
	
	if (HitResult.GetActor())
	{
		FVector Location = HitResult.GetActor()->GetActorLocation();
		PhysicsHandle->GrabComponentAtLocationWithRotation(
			ComponentToGrab,
			NAME_None,
			Location,
			Rotate
		);
	}
	


}


void UGrabbingSystem::Release()
{
	UE_LOG(LogTemp, Warning, TEXT("Grabbing button relesed."));

	FHitResult HitResult = GetFirstPhysicsBodyWithinReach();
	UPrimitiveComponent* ComponentToGrab = HitResult.GetComponent();
	PhysicsHandle->ReleaseComponent();

}


void UGrabbingSystem::FindPhysicsHandle()
{
	PhysicsHandle = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();

	if (PhysicsHandle)
	{
		//PhysicsHandle is found.
	}else
	{
		UE_LOG(LogTemp, Error, TEXT("Component PhysicsHandle not found on: %s."), *GetOwner()->GetName());
	}

}


void UGrabbingSystem::SetupInputComponent()
{
	PlayerInput = GetOwner()->FindComponentByClass<UInputComponent>();

	if (PlayerInput)
	{
			// Binding Keys:
			// Name of binding in Project Settings,
			// What kind of press (long, double, etc.),
			// The actor, this,
			// Function that is executed, address.

		PlayerInput->BindAction("GrabObject", IE_Pressed, this, &UGrabbingSystem::Grab);
		PlayerInput->BindAction("GrabObject", IE_Released, this, &UGrabbingSystem::Release);
	}}



// Called every frame
void UGrabbingSystem::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	//For Testing
		GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
			OUT PlayerViewLocation,
			OUT PlayerViewRotation
		);
		FVector LineTraceDirection = PlayerViewRotation.Vector();
		FVector LineTraceEnd = PlayerViewLocation + (LineTraceDirection * GrabbingReach);
	//

	if (PhysicsHandle->GrabbedComponent)
	{
		PhysicsHandle->SetTargetLocation(LineTraceEnd);
	}
	

}




FHitResult UGrabbingSystem::GetFirstPhysicsBodyWithinReach()
{
	//GetPlayerViewpoint
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
		OUT PlayerViewLocation,
		OUT PlayerViewRotation
	);

	FVector LineTraceDirection = PlayerViewRotation.Vector();
	FVector LineTraceEnd = PlayerViewLocation + (LineTraceDirection * GrabbingReach);

	FHitResult Hit;

	//Ray cast out
	FCollisionQueryParams TraceParams(
		FName(TEXT("")),
		false,
		GetOwner()
	);

	GetWorld()->LineTraceSingleByObjectType(
		OUT Hit,
		PlayerViewLocation,
		LineTraceEnd,
		FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody),
		TraceParams
	);


	//See what it hits
	if (Hit.IsValidBlockingHit())
	{
		FString Object = Hit.GetActor()->GetName();
		UE_LOG(LogTemp, Warning, TEXT("You hit object: %s"), *Object);
	}
	
	return Hit;
}
