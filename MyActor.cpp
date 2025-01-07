// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AMyActor::RandomMove(FVector2D& _Move)
{
	_Move.X = FMath::RandRange(-1, 1);
	_Move.Y = FMath::RandRange(-1, 1);
}

void AMyActor::DisplayMove(FVector2D _Coor, FVector2D _Move)
{
	UE_LOG(LogTemp, Log, TEXT("현재 좌표 : (%.0f, %.0f) +++ 이동 좌표(%.0f, %.0f) === 목표 좌표 : (%.0f, %.0f)"), _Coor.X, _Coor.Y, _Move.X, _Move.Y, _Coor.X + _Move.X, _Coor.Y + _Move.Y);
}

double AMyActor::Step(FVector2D& _Coor, FVector2D _Move, int& _cnt)
{
	const int32 Standard = 50;
	_Coor.X += _Move.X;
	_Coor.Y += _Move.Y;


	if (FMath::RandRange(1, 100) > Standard)
	{
		ActiveEvent();
		_cnt++;
	}

	return Distance(_Move.X, _Move.Y);
}

double AMyActor::Distance(double _x, double _y)
{
	double distance = FMath::Sqrt(_x * _x + _y * _y);
	UE_LOG(LogTemp, Log, TEXT("이동 거리 : %f"), distance);
	return distance;
}

void AMyActor::ActiveEvent()
{
	UE_LOG(LogTemp, Display, TEXT("이벤트 동작됨(확률50)"));
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	FVector2D MyCoordinate = FVector2D::ZeroVector;
	FVector2D MoveVector;

	double Sum = 0;
	int cnt = 0;

	UE_LOG(LogTemp, Warning, TEXT("Hello World!"));

	for (int32 i = 0; i < 10; i++)
	{
		RandomMove(MoveVector);
		DisplayMove(MyCoordinate, MoveVector);
		Sum += Step(MyCoordinate, MoveVector, cnt);
	}

	UE_LOG(LogTemp, Display, TEXT("총 이동 거리 : %f, 총 이벤트 동작 횟수 : %d"), Sum, cnt);
}

