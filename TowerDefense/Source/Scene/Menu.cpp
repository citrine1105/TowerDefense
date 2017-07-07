#include "../../Header/Scene/Menu.h"

cMenuScene::cMenuScene(iSceneChanger<eScene> *Changer) : cScene(Changer) {

}

void cMenuScene::Initialize() {
	mColumn.SetPosition(-480.0, 240.0);
	mColumn.MoveToPoint(320.0, 240.0, 30, eEasing_Quint);
}

void cMenuScene::Finalize() {

}

void cMenuScene::Update() {
	cScene::Update();
	mColumn.Update();
	if (mKeyboard.GetInputState(KEY_INPUT_Z) == 60) {
		pSceneChanger->ChangeScene(eScene_Game);
	}
}

void cMenuScene::Draw() {
	double tX, tY;
	mColumn.GetPosition(&tX, &tY);
	DrawFormatString(0, 0, GetColor(0xFF, 0xFF, 0xFF), _T("%.1f:%.1f"), tX, tY);
	DrawStringF(tX, tY, _T("Howdy!"), GetColor(0xFF, 0xFF, 0x00));
}