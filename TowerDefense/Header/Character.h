#pragma once
#include "Sprite.h"
#include "FontContainer.h"

class cCharacter : public cSprite {
protected:
	cTimer mAnimationTimer;
	int mLife;
	int mMaxLife;
	int mAttack;
	int mDefense;
public:
	cCharacter();
	~cCharacter();

	void SetLife(const int Life);

	void Initialize() override;
	void Finalize() override;
	void Update() override;
	void Draw() override;
};