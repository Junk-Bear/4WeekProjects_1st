// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class PROJECTS_4THWEEK_1ST_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor();

	void RandomMove(FVector2D&);
	void DisplayMove(FVector2D, FVector2D);
	double Step(FVector2D&, FVector2D, int&);
	double Distance(double, double);
	void ActiveEvent();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
