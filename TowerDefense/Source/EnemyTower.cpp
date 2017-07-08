#include "../Header/EnemyTower.h"

cEnemyTower::cEnemyTower() {
	cTower::Initialize();
}

cEnemyTower::~cEnemyTower() {
	cTower::Finalize();
}

void cEnemyTower::Draw() {
	DrawRotaGraphF(mPositionX, mPositionY, 1.0, 0.0, cImageResourceContainer::GetInstance()->GetElement(eImage_Tower)->GetHandle(), TRUE, TRUE);

	DrawBoxAA(mPositionX - 64.0, mPositionY - 64, mPositionX - 64.0 + 128.0, mPositionY - 56, GetColor(0x7F, 0x00, 0x00), TRUE);
	DrawBoxAA(mPositionX - 64.0, mPositionY - 64, mPositionX - 64.0 + 128.0 * (static_cast<double>(mLife) / static_cast<double>(mMaxLife)), mPositionY - 56, GetColor(0xFF, 0x00, 0x00), TRUE);
	cTower::Draw();
}