#include "../Header/PlayerTower.h"

cPlayerTower::cPlayerTower() {
	cTower::Initialize();
}

cPlayerTower::~cPlayerTower() {
	cTower::Finalize();
}

void cPlayerTower::Draw() {
	DrawRotaGraphF(mPositionX, mPositionY, 1.0, 0.0, cImageResourceContainer::GetInstance()->GetElement(eImage_Tower)->GetHandle(), TRUE, FALSE);

	DrawBoxAA(mPositionX - 64.0, mPositionY - 64, mPositionX - 64.0 + 128.0 * (static_cast<double>(mLife) / static_cast<double>(mMaxLife)), mPositionY - 56, GetColor(0x00, 0xFF, 0x00), TRUE);
	cTower::Draw();
}