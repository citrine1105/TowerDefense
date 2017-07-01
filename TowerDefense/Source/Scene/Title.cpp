#include "../../Header/Scene/Title.h"

cTitleScene::cTitleScene(iSceneChanger<eScene> *Changer) : cScene(Changer) {

}

void cTitleScene::Initialize() {
	mMessageFade.SetPosition(0.0, 0.0);
}

void cTitleScene::Finalize() {

}

void cTitleScene::Update() {
	cScene::Update();
	mMessageFade.Update();
	double tValue;
	mMessageFade.GetPosition(&tValue, nullptr);

	if (tValue <= 0.0) {
		mMessageFade.MoveToPoint(255.0, 0.0, 45, eEasing_Sine);
	}
	else if (tValue >= 250.0) {
		mMessageFade.MoveToPoint(0.0, 0.0, 45, eEasing_Sine);
	}

	if (mKeyboard.GetInputState(KEY_INPUT_RETURN) == 1 ||
		mMouse.GetInputState(MOUSE_INPUT_LEFT) == 1) {
		pSceneChanger->ChangeScene(eScene_Menu);
	}
}

void cTitleScene::Draw() {
	//DrawString(0, 0, _T("TowerDefenseÉ^ÉCÉgÉãâÊñ "), GetColor(0xFF, 0xFF, 0xFF));
	//cScene::Draw();
	double tValue;
	std::tstring tVersion;

	tVersion = _T("Ver ");
	tVersion += VERSION_STRING;

	mMessageFade.GetPosition(&tValue, nullptr);
	DrawStringToHandle(SCREEN_WIDTH / 2 - GetDrawStringWidthToHandle(_T("Tower Defense"), _tcslen(_T("Tower Defense")), mMainFont) / 2, SCREEN_HEIGHT / 5 * 2, _T("Tower Defense\n(Ç±ÇÍâÊëúÇ…ç∑Çµë÷Ç¶Ç∆Ç¢Çƒ)"), GetColor(0xFF, 0xFF, 0xFF), mMainFont);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, static_cast<int>(tValue));
	DrawStringToHandle(SCREEN_WIDTH / 2 - GetDrawStringWidthToHandle(_T("Press [Enter] Key or Mouse Click"), _tcslen(_T("Press [Enter] Key or Mouse Click")), mMainFont) / 2, SCREEN_HEIGHT / 5 * 4, _T("Press [Enter] Key or Mouse Click"), GetColor(0xFF, 0xFF, 0xFF), mMainFont);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
	DrawStringToHandle(SCREEN_WIDTH - GetDrawStringWidthToHandle(tVersion.c_str(), tVersion.size(), mMainFont) - 16, SCREEN_HEIGHT - 40, tVersion.c_str(), GetColor(0xFF, 0xFF, 0xFF), mMainFont);
}