#include "../Header/PlayerCharacter.h"

cPlayerCharacter::cPlayerCharacter() {
	this->Initialize();
}

cPlayerCharacter::~cPlayerCharacter() {
	this->Finalize();
}

//void cPlayerCharacter::SetTarget(cEnemyCharacter *Character) {
//	pTargetCharacter = static_cast<cCharacter*>(Character);
//}

void cPlayerCharacter::Initialize() {
	this->Initialize(eChara_Type1, 1, 1, 1, 1.0);
}

void cPlayerCharacter::Initialize(const eCharacterType Type, const int Life, const int Attack, const int Defense, const double Speed) {
	cCharacter::Initialize(Type, Life, Attack, Defense, Speed);
	mPositionX = SCREEN_WIDTH * 6 / 7;
	this->mMoveVector.SetElement(-mSpeed, 0.0);
}

void cPlayerCharacter::Draw() {
	DrawRotaGraphF(static_cast<float>(mPositionX), static_cast<float>(mPositionY), 1.0, 0.0,
		cImageResourceContainer::GetInstance()->GetElement(eImage_Character1)->GetHandle(mAnimationTimer.GetValue() / 2 % 2), TRUE, FALSE);

	DrawBoxAA(mPositionX - 32.0, mPositionY - 64, mPositionX - 32.0 + 64.0, mPositionY - 56, GetColor(0x00, 0x7F, 0x00), TRUE);
	DrawBoxAA(mPositionX - 32.0, mPositionY - 64, mPositionX - 32.0 + 64.0 * (static_cast<double>(mLife) / static_cast<double>(mMaxLife)), mPositionY - 56, GetColor(0x00, 0xFF, 0x00), TRUE);
	cCharacter::Draw();
}