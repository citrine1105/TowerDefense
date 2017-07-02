#include "../Header/Character.h"

cCharacter::cCharacter() {
	this->Initialize();
}

cCharacter::~cCharacter() {
	this->Finalize();
}

void cCharacter::SetLife(const int Life) {
	mMaxLife = Life;
	mLife = mMaxLife;
}

void cCharacter::Initialize() {
	cSprite::Initialize();
	mAnimationTimer.Initialize();
	mAnimationTimer.SetCountMode(eCountMode_CountUp);
	mAnimationTimer.Start();

	mPositionX = SCREEN_WIDTH / 5 * 4;
	mPositionY = SCREEN_HEIGHT / 2;

	mLife = 1;
	mMaxLife = 1;
	mAttack = 1;
	mDefense = 1;
	this->mMoveVector.SetElement(-1.4, 0.0);

	//printfDx(_T("Called cCharacter::Initialize()\n"));
}

void cCharacter::Finalize() {
	cSprite::Finalize();
	mAnimationTimer.Finalize();
	mLife = 0;
	mMaxLife = 0;
	mAttack = 0;
	mDefense = 0;
}

void cCharacter::Update() {
	cSprite::Update();
	mAnimationTimer.Update();
	this->Move();
	//printfDx(_T("Called cCharacter::Update()\n"));
}

void cCharacter::Draw() {
	std::tstring tLifeInfo;
	tLifeInfo = std::to_tstring(mLife);
	tLifeInfo += _T("/");
	tLifeInfo += std::to_tstring(mMaxLife);

	DrawRotaGraphF(static_cast<float>(mPositionX), static_cast<float>(mPositionY), 1.0, 0.0, 
		cImageResourceContainer::GetInstance()->GetElement(eImage_Character1)->GetHandle(mAnimationTimer.GetValue() / 2 % 2), TRUE);

	DrawStringFToHandle(mPositionX - GetDrawStringWidthToHandle(tLifeInfo.c_str(), tLifeInfo.size(), cFontContainer::GetInstance()->GetElement(eFont_GameInfoFont)) / 2, mPositionY - 48 - 24, tLifeInfo.c_str(), GetColor(0xFF, 0xFF, 0xFF), cFontContainer::GetInstance()->GetElement(eFont_GameInfoFont));
}