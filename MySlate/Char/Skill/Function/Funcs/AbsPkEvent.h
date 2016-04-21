// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AbsPkEvent.generated.h"

class UPkMsg;
class UAbsBuff;

UCLASS()
class UAbsPkEvent : public UObject
{
	GENERATED_BODY()

public:
	struct PkInfo
	{
		PkInfo(int32 attId, int sId, int32 targetId, UAbsBuff* buff)
			:attUniqueId(attId)
			, skillId(sId)
			, targetUniqueId(targetId)
			, buffer(buff)
		{
		}

		uint32_t attUniqueId;	//buffer�ͷ���
		int skillId;			//�ͷ�buffer�ļ���
		uint32_t targetUniqueId;//buffer������
		UAbsBuff* buffer;	//buffer
	};

public:
	UAbsPkEvent();
	virtual ~UAbsPkEvent();
	virtual void BeginDestroy() override;

	virtual UAbsPkEvent* Clone() { return nullptr; }

	virtual void RunBeforeSkill(UPkMsg* msg) {}
	virtual void RunBeforePk(UPkMsg* msg) {}
	virtual void RunBeforeEvns(UPkMsg* msg) {}
	virtual void RunEndEvns(UPkMsg* msg) {}
	virtual void RunEndPk(UPkMsg* msg) {}
	virtual void RunEndSkill(UPkMsg* msg) {}

	virtual void Parser(const TArray<FString>& _params) {}//��������

	FString		GetKey() const { return mKey; }
	void		SetKey(const FString& _key) { mKey = _key; }

protected:
	bool CheckPercent(const FString& _value);

protected:
	FString		mKey;
	bool		mIsPercent;
};