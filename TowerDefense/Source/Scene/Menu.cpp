#include "../../Header/Scene/Menu.h"

cMenuScene::cMenuScene(iSceneChanger<eScene> *Changer) : cScene(Changer) {

}

void cMenuScene::Initialize() {
	mColumn.SetPosition(-480.0, 240.0);
	mColumn.MoveToPoint(320.0, 240.0, 30, eEasing_Quint);
	Menubutton[0].SetCollisionRange(100, 100);
	Menubutton[0].SetPosition(320.0, 200.0);
}

void cMenuScene::Finalize() {

}

void cMenuScene::Update() {
	cScene::Update();
	mColumn.Update();
	if (mKeyboard.GetInputState(KEY_INPUT_Z) == 60) {
		pSceneChanger->ChangeScene(eScene_Game);
	}
	if (Menubutton[0].GetCollisionFlag(mMouse.GetSprite()) && mMouse.GetInputState(MOUSE_INPUT_LEFT) == 1) {
		pSceneChanger->ChangeScene(eScene_Game);
	}
}

void cMenuScene::Draw() {
	double tX, tY;
	mColumn.GetPosition(&tX, &tY);
	DrawFormatString(0, 0, GetColor(0xFF, 0xFF, 0xFF), _T("%.1f:%.1f"), tX, tY);
	DrawStringF(tX, tY, _T("Howdy!"), GetColor(0xFF, 0xFF, 0x00));
	DrawFormatString(260, 200, GetColor(255, 255, 255), _T("この辺にスタートボタンあるよ"));
}