#include "../Header/Tower.h"

cTower::cTower() {
	this->Initialize();
}

cTower::~cTower() {
	this->Finalize();
}

void cTower::Damage(const int Damage) {
	mLife -= Damage;
	if (mLife < 0) {
		mLife = 0;
	}
}

void cTower::SetLife(const int Life) {
	if (Life > 0) {
		mMaxLife = Life;
		mLife = mMaxLife;
	}
}

int cTower::GetLife() {
	return mLife;
}

void cTower::Initialize() {
	mLife = 1;
	mMaxLife = 1;
	//mDefense = 1;
	this->SetCollisionRange(96.0, 96.0);
}

void cTower::Finalize() {
	mLife = 0;
	mMaxLife = 0;
	//mDefense = 0;
}

void cTower::Update() {

}

void cTower::Draw() {
	std::tstring tLifeInfo;
	tLifeInfo = std::to_tstring(mLife);
	tLifeInfo += _T("/");
	tLifeInfo += std::to_tstring(mMaxLife);

	DrawStringFToHandle(mPositionX - GetDrawStringWidthToHandle(tLifeInfo.c_str(), tLifeInfo.size(), cFontContainer::GetInstance()->GetElement(eFont_GameInfoFont)) / 2, mPositionY - 48 - 24 - 16, tLifeInfo.c_str(), GetColor(0xFF, 0xFF, 0xFF), cFontContainer::GetInstance()->GetElement(eFont_GameInfoFont));
}