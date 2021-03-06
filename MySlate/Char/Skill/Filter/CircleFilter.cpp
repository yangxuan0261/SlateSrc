
#include "MySlate.h"
#include "CircleFilter.h"

#include "../Pk/PkMsg.h"
#include "../../MyChar.h"
#include "../../Object/ObjMgr.h"

UCircleFilter::UCircleFilter() : Super()
{
}

UCircleFilter::~UCircleFilter()
{
	UE_LOG(FilterLogger, Warning, TEXT("--- UCircleFilter::~UCircleFilter"));
}
 
void UCircleFilter::BeginDestroy()
{
	UE_LOG(FilterLogger, Warning, TEXT("--- UCircleFilter::BeginDestroy"));
	Super::BeginDestroy();
}

void UCircleFilter::Reset()
{
	Super::Reset();
	mRadius = 100;
}

void UCircleFilter::Filter(UPkMsg* _msg, EFilterType _filterType /* = EFilterType::Locked */, float _radius /* = 0.f */, const FVector& _boxSize /* = FVector::ZeroVector */)
{
	Super::Filter(_msg, EFilterType::Circle, mRadius);

}

UAbsFilter* UCircleFilter::Clone()
{
	return CreateFilter(mKey);
}

void UCircleFilter::Parser(const TArray<FString>& _params)
{
	if (_params.Num() == 3)
	{
		mSelectType = (ESelectType)FCString::Atoi(*_params[0]);
		mCount = FCString::Atoi(*_params[1]);
		mRadius = FCString::Atoi(*_params[2]);
	}
	else
	{
		UE_LOG(FilterLogger, Error, TEXT("--- UCircleFilter::Parser, _params.Num() = %d"), _params.Num());
	}
}

UCircleFilter* UCircleFilter::CreateFilter(const FString& _key)
{
	UCircleFilter* circleFilter = gGetObjMgr()->GetObj<UCircleFilter>(gGetObjMgr()->mCircleFltCls);
	circleFilter->SetKey(_key);
	return circleFilter;
}
