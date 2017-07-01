#include "../../Header/Scene/Load.h"

cLoadScene::cLoadScene(iSceneChanger<eScene> *Changer) : cScene(Changer) {

}

void cLoadScene::Initialize() {
	mMainFont = CreateFontToHandle(_T("ＭＳ Ｐ明朝"), SCREEN_HEIGHT / 30, 0, DX_FONTTYPE_ANTIALIASING_EDGE_4X4);
}

void cLoadScene::Finalize() {

}

void cLoadScene::Update() {
	cScene::Update();
	if (GetASyncLoadNum() == 0) {
		pSceneChanger->ChangeScene(eScene_Title);
	}
}

void cLoadScene::Draw() {
	DrawString(0, 0, _T("Loading"), GetColor(0xFF, 0xFF, 0xFF));
}