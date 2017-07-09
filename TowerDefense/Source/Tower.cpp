#include "../Header/Tower.h"

cTower::cTower() {
	this->Initialize();
}

cTower::~cTower() {
	this->Finalize();
}

void cTower::SetLife(const int Life) {
	mMaxLife = Life;
	mLife = mMaxLife;
}

void cTower::Initialize() {
	cCharacter::Initialize(eChara_Type1, 1, 0, 0, 0.0, 1);
	this->SetCollisionRange(48.0, 96.0);
}

void cTower::Draw() {
	std::tstring tLifeInfo;
	tLifeInfo = std::to_tstring(mLife);
	tLifeInfo += _T("/");
	tLifeInfo += std::to_tstring(mMaxLife);

	DrawStringFToHandle(mPositionX - GetDrawStringWidthToHandle(tLifeInfo.c_str(), tLifeInfo.size(), cFontContainer::GetInstance()->GetElement(eFont_GameInfoFont)) / 2, mPositionY - 48 - 24 - 16, tLifeInfo.c_str(), GetColor(0xFF, 0xFF, 0xFF), cFontContainer::GetInstance()->GetElement(eFont_GameInfoFont));
}