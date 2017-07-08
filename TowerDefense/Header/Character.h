#pragma once
#include "Sprite.h"
#include "FontContainer.h"

enum eCharacterType {
	eChara_Type1,
	eChara_Type2,
	eChara_Type3,

	eChara_None
};

class cCharacter : public cSprite {
protected:
	cTimer mAnimationTimer;
	eCharacterType mType;
	cCharacter *pTargetCharacter;
	int mLife;
	int mMaxLife;
	int mAttack;
	int mDefense;
	double mSpeed;
	bool fActive;
public:
	cCharacter();
	~cCharacter();

	void Damage(const int Damage);
	void SetTarget(cCharacter *Character);
	cCharacter* GetTarget();
	int GetLife();
	bool GetActiveFlag();

	virtual void Initialize() override;
	virtual void Initialize(eCharacterType Type, const int Life, const int Attack, const int Defense, const double Speed);
	void Finalize() override;
	void Update() override;
	virtual void Draw() override;
};