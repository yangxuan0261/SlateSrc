// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Common/ISingleton.h"
#include "FunctionFactory.generated.h"

class UAbsPkEvent;
class UAbsFilter;

UCLASS()
class UFunctionFactory : public UObject, public USingleton<UFunctionFactory>
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	UFunctionFactory();
	virtual ~UFunctionFactory();

	UAbsFilter* createFilter(const FString& _str);//根据样板产出对象(选人)

private:
	TMap<FString, UAbsPkEvent*>	m_productFormer;
	TMap<FString, UAbsPkEvent*>	m_filterMap;
};
