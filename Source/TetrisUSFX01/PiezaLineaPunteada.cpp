// Fill out your copyright notice in the Description page of Project Settings.
#include "PiezaLineaPunteada.h"
#include <vector>
#include "Pieza.h"


// Sets default values
APiezaLineaPunteada::APiezaLineaPunteada()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}
void APiezaLineaPunteada::spawnPieza() {

	if (Pieza == nullptr) {
		UE_LOG(LogTemp, Log, TEXT("NULLPTR DE PIEZA CRUZ!"));
	}
	else {
		UE_LOG(LogTemp, Log, TEXT("SI HAY PIEZA! en PIEZA CRUZ"));
	}
	FVector Location(0.0, 5, 500);
	FRotator Rotation(0.0, 0.0, 0.0);
	Pieza = GetWorld()->SpawnActor<APieza>(APieza::StaticClass(), Location, Rotation);
	Pieza->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
}
void APiezaLineaPunteada::buildBloques() {
	if (!Pieza) {
		UE_LOG(LogTemp, Error, TEXT("No hay pieza, es NULL, inicializala"));
		return;
	}
	else {
		std::vector<std::vector<std::pair<float, float>>> Shapes =
		{
			/*{{-20.0, 0.0}, {-10.0, 0.0}, {0.0, 0.0}, {10.0, 0.0}},*/
			{{0.0, 10.0}, {0.0, 0.0}, {10.0, 0.0}, {20.0, 0.0}},
			/*{{-20.0, 0.0}, {-10.0, 0.0}, {0.0, 0.0}, {0.0, 10.0}},
			{{0.0, 0.0}, {10.0, 0.0}, {0.0, -10.0}, {10.0, -10.0}},
			{{-10.0, -10.0}, {0.0, -10.0}, {0.0, 0.0}, {10.0, 0.0}},
			{{-10.0, 0.0}, {0.0, 0.0}, {0.0, 10.0}, {10.0, 0.0}},
			{{-10.0, 0.0}, {0.0, 0.0}, {0.0, -10.0}, {10.0, -10.0}},*/
		};
		const int Index = FMath::RandRange(0, Shapes.size() - 1);
		UE_LOG(LogTemp, Warning, TEXT("index=%d"), Index);

		const std::vector<std::pair<float, float>>& YZs = Shapes[Index];
		TMultiMap<FString, std::pair<float, float>> bloquesTmap;
		UE_LOG(LogTemp, Log, TEXT("LLENANDO TMAP!"));

		UE_LOG(LogTemp, Log, TEXT("Mandando A PIEZA!"));

		for (auto&& YZ : YZs)
		{
			bloquesTmap.Add(TEXT("color"), { YZ.first, YZ.second });
		}
		Pieza->setBloques(bloquesTmap);
		return;
	}
}
/*{
	if (!Pieza) {
		UE_LOG(LogTemp, Error, TEXT("No hay pieza, es NULL, inicializala"));
		return;
	}
	else {
		TMultiMap<FString, std::pair<float, float>> bloquesTmap;
		UE_LOG(LogTemp, Log, TEXT("LLENANDO TMAP!"));

		bloquesTmap.Add(TEXT("temporal"), { 40,0 });
		bloquesTmap.Add(TEXT("temporal"), { 20,0 });
		bloquesTmap.Add(TEXT("temporal"), { 0,0 });
		bloquesTmap.Add(TEXT("temporal"), { -20,0 });
		bloquesTmap.Add(TEXT("temporal"), { -40,0 });

		UE_LOG(LogTemp, Log, TEXT("Mandando A PIEZA!"));
		Pieza->setBloques(bloquesTmap);

		return;
	}

}*/
// Called when the game starts or when spawned
void APiezaLineaPunteada::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APiezaLineaPunteada::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
APieza* APiezaLineaPunteada::GetPieza() {
	return Pieza;
}

