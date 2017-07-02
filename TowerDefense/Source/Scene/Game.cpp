#include "../../Header/Scene/Game.h"

cGameScene::cGameScene(iSceneChanger<eScene> *Changer) : cScene(Changer) {

}

void cGameScene::Initialize() {
	for (int i = 0; i < 5; i++) {
		mButton[i].SetCollisionRange(96.0, 96.0);
		mPauseButton.SetCollisionRange(64.0, 64.0);
	}

	mButton[0].SetPosition(SCREEN_WIDTH / 2.0 + (-96.0 - 32.0) * 2.0, SCREEN_HEIGHT - 48.0 - 24.0);
	mButton[1].SetPosition(SCREEN_WIDTH / 2.0 + (-96.0 - 32.0) * 1.0, SCREEN_HEIGHT - 48.0 - 24.0);
	mButton[2].SetPosition(SCREEN_WIDTH / 2.0 + (-96.0 - 32.0) * 0.0, SCREEN_HEIGHT - 48.0 - 24.0);
	mButton[3].SetPosition(SCREEN_WIDTH / 2.0 - (-96.0 - 32.0) * 1.0, SCREEN_HEIGHT - 48.0 - 24.0);
	mButton[4].SetPosition(SCREEN_WIDTH / 2.0 - (-96.0 - 32.0) * 2.0, SCREEN_HEIGHT - 48.0 - 24.0);

	mPauseButton.SetPosition(32.0 + 36.0, 32.0 + 24.0);
}

void cGameScene::Finalize() {

}

void cGameScene::Update() {
	cScene::Update();
	for (int i = 0; i < mCharacter.size(); i++) {
		mCharacter[i].Update();
	}
}

void cGameScene::Draw() {
	double tPosX, tPosY;
	std::tstring tAreaName;
	std::tstring tMoney;

	tAreaName = _T("エリア名も書けるぞ");
	tMoney = std::to_wstring(114514);
	tMoney += _T("G");

	//DrawExtendGraph(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, cImageResourceContainer::GetInstance()->GetElement(eImage_TitleBackground)->GetHandle(), FALSE);

	DrawGraph(SCREEN_WIDTH / 6, SCREEN_HEIGHT / 2, cImageResourceContainer::GetInstance()->GetElement(eImage_Tower)->GetHandle(), TRUE);

	for (int i = 0; i < 5; i++) {
		mButton[i].GetPosition(&tPosX, &tPosY);
		if (mButton[i].GetCollisionFlag(mMouse.GetSprite())) {
			if (mMouse.GetInputState(MOUSE_INPUT_LEFT) == 1) {
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, 64);
				cCharacter *tCh = new cCharacter;
				tCh->SetLife(500);
				mCharacter.push_back(*tCh);
				delete tCh;
			}
			else {
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
			}
		}
		//DrawRotaGraph(tPosX, tPosY, 1.0, DEGREE_TO_RADIAN(0.0), cImageResourceContainer::GetInstance()->GetElement(eImage_GameButton)->GetHandle(), TRUE);
		DrawGraph(static_cast<int>(tPosX - 48.0), static_cast<int>(tPosY - 48.0), cImageResourceContainer::GetInstance()->GetElement(eImage_GameButton)->GetHandle(), TRUE);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
	}

	mPauseButton.GetPosition(&tPosX, &tPosY);
	DrawGraph(static_cast<int>(tPosX - 32.0), static_cast<int>(tPosY - 32.0), cImageResourceContainer::GetInstance()->GetElement(eImage_PauseButton)->GetHandle(), TRUE);

	DrawStringToHandle(36 + 64 + 32, 24 + 6, tAreaName.c_str(), GetColor(0xFF, 0xFF, 0xFF), cFontContainer::GetInstance()->GetElement(eFont_GameMoneyFont), GetColor(0x77, 0x4D, 0x28));
	DrawStringToHandle(SCREEN_WIDTH - GetDrawStringWidthToHandle(tMoney.c_str(), tMoney.size(), cFontContainer::GetInstance()->GetElement(eFont_GameMoneyFont)) - 36, 24, tMoney.c_str(), GetColor(0xF2, 0xCD, 0x54), cFontContainer::GetInstance()->GetElement(eFont_GameMoneyFont), GetColor(0x60, 0x39, 0x16));

	for (int i = 0; i < mCharacter.size(); i++) {
		mCharacter[i].Draw();
	}
	//mMouse.Draw();
}