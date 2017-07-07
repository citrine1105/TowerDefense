#include "../Header/Character.h"

cCharacter::cCharacter() {
	this->Initialize();
}

cCharacter::~cCharacter() {
	this->Finalize();
}

void cCharacter::Damage(const int Damage) {
	mLife -= Damage;
	if (mLife < 0) {
		mLife = 0;
	}
}

int cCharacter::GetLife() {
	return mLife;
}

bool cCharacter::GetActiveFlag() {
	return fActive;
}

void cCharacter::Initialize() {
	this->Initialize(eChara_Type1, 1, 1, 1, 1.0);
}

void cCharacter::Initialize(eCharacterType Type, const int Life, const int Attack, const int Defense, const double Speed) {
	cSprite::Initialize();
	mAnimationTimer.Initialize();
	mAnimationTimer.SetCountMode(eCountMode_CountUp);
	mAnimationTimer.Start();

	mType = Type;

	mPositionY = SCREEN_HEIGHT * 51 / 72;

	mMaxLife = Life;
	mLife = mMaxLife;
	mAttack = Attack;
	mDefense = Defense;
	mSpeed = Speed;

	this->SetCollisionRange(64.0, 64.0);

	fActive = true;
}

void cCharacter::Finalize() {
	cSprite::Finalize();
	mAnimationTimer.Finalize();
	mLife = 0;
	mMaxLife = 0;
	mAttack = 0;
	mDefense = 0;
	mSpeed = 0.0;
}

void cCharacter::Update() {
	cSprite::Update();
	mAnimationTimer.Update();
	Move();

	if (mPositionX < 0.0 || mPositionX > static_cast<double>(SCREEN_WIDTH)) {
		fActive = false;
	}
}

void cCharacter::Draw() {
	std::tstring tLifeInfo;
	tLifeInfo = std::to_tstring(mLife);
	tLifeInfo += _T("/");
	tLifeInfo += std::to_tstring(mMaxLife);

	DrawStringFToHandle(mPositionX - GetDrawStringWidthToHandle(tLifeInfo.c_str(), tLifeInfo.size(), cFontContainer::GetInstance()->GetElement(eFont_GameInfoFont)) / 2, mPositionY - 48 - 24 - 16, tLifeInfo.c_str(), GetColor(0xFF, 0xFF, 0xFF), cFontContainer::GetInstance()->GetElement(eFont_GameInfoFont));
}