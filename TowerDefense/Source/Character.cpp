#include "../Header/Character.h"

cCharacter::cCharacter() : pTargetCharacter(nullptr) {
	this->Initialize();
}

cCharacter::~cCharacter() {
	this->Finalize();
}

void cCharacter::Damage(const int Damage) {
	if (Damage - mDefense <= 0) {	// 防御力がダメージ量を上回る場合
		mLife -= 1;
	}
	else {
		mLife -= Damage - mDefense;	// ダメージ量-防御力
	}
	if (mLife < 0) {
		mLife = 0;	// 負数にならない
	}

	if (mLife <= 0) {	// 体力が0になったら
		fActive = false;		// 登録解除
	}
}

void cCharacter::SetTarget(cCharacter *Character) {
	pTargetCharacter = Character;
}

cCharacter* cCharacter::GetTarget() {
	return pTargetCharacter;
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

	this->SetCollisionRange(16.0, 64.0);

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
	if (pTargetCharacter == nullptr) {
		Move();
	}
	else {
		pTargetCharacter->Damage(mAttack);
		if (pTargetCharacter->GetLife() <= 0) {
			this->SetTarget(nullptr);
		}
	}

	if (mPositionX < 0.0 || mPositionX > static_cast<double>(SCREEN_WIDTH)) {	// 画面外に到達した場合
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