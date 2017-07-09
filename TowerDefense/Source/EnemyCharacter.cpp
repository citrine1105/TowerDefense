#include "../Header/EnemyCharacter.h"

cEnemyCharacter::cEnemyCharacter() {
	this->Initialize(eChara_Type1, 1, 1, 1, 1.0, 1);
}

cEnemyCharacter::~cEnemyCharacter() {
	this->Finalize();
}

void cEnemyCharacter::Initialize(const eCharacterType Type, const int Life, const int Attack, const int Defense, const double Speed, const int AttackInverval) {
	cCharacter::Initialize(Type, Life, Attack, Defense, Speed, AttackInverval);
	mPositionX = SCREEN_WIDTH / 7;
	this->mMoveVector.SetElement(mSpeed, 0.0);
}

void cEnemyCharacter::Draw() {
	std::tstring tLifeInfo;
	tLifeInfo = std::to_tstring(mLife);
	tLifeInfo += _T("/");
	tLifeInfo += std::to_tstring(mMaxLife);

	DrawRotaGraphF(static_cast<float>(mPositionX), static_cast<float>(mPositionY), 1.0, 0.0,
		cImageResourceContainer::GetInstance()->GetElement(eImage_Character1)->GetHandle(mAnimationTimer.GetValue() / 3 % 3), TRUE, TRUE);

	DrawBoxAA(mPositionX - 32.0, mPositionY - 64, mPositionX - 32.0 + 64.0, mPositionY - 56, GetColor(0x7F, 0x00, 0x00), TRUE);
	DrawBoxAA(mPositionX - 32.0, mPositionY - 64, mPositionX - 32.0 + 64.0 * (static_cast<double>(mLife) / static_cast<double>(mMaxLife)), mPositionY - 56, GetColor(0xFF, 0x00, 0x00), TRUE);
	DrawStringFToHandle(mPositionX - GetDrawStringWidthToHandle(tLifeInfo.c_str(), tLifeInfo.size(), cFontContainer::GetInstance()->GetElement(eFont_GameInfoFont)) / 2, mPositionY - 48 - 24 - 16, tLifeInfo.c_str(), GetColor(0xFF, 0xFF, 0xFF), cFontContainer::GetInstance()->GetElement(eFont_GameInfoFont));
}