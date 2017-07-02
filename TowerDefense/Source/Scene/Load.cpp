#include "../../Header/Scene/Load.h"

cLoadScene::cLoadScene(iSceneChanger<eScene> *Changer) : cScene(Changer) {

}

void cLoadScene::Initialize() {
	cFontContainer::GetInstance()->SetElement(eFont_MainFont, CreateFontToHandle(_T("ＭＳ Ｐ明朝"), SCREEN_HEIGHT / 30, 0, DX_FONTTYPE_ANTIALIASING_EDGE_4X4));
	cFontContainer::GetInstance()->SetElement(eFont_GameInfoFont, CreateFontToHandle(_T("ＭＳ Ｐ明朝"), SCREEN_HEIGHT / 48, 0, DX_FONTTYPE_ANTIALIASING_EDGE_4X4));
	cFontContainer::GetInstance()->SetElement(eFont_GameMoneyFont, CreateFontToHandle(_T("ＭＳ Ｐ明朝"), SCREEN_HEIGHT / 16, 0, DX_FONTTYPE_ANTIALIASING_EDGE_4X4));

	cImageResourceContainer::GetInstance()->GetElement(eImage_TitleBackground)->Load(_T("./Data/Image/1080p_dummy.png"));
	cImageResourceContainer::GetInstance()->GetElement(eImage_Tower)->Load(_T("./Data/Image/Game/tower.png"));
	cImageResourceContainer::GetInstance()->GetElement(eImage_Character1)->Load(_T("./Data/Image/Game/chara1.png"), 2, 2, 1, 96, 96);
	cImageResourceContainer::GetInstance()->GetElement(eImage_Character2)->Load(_T("./Data/Image/Game/chara1.png"), 2, 2, 1, 96, 96);
	cImageResourceContainer::GetInstance()->GetElement(eImage_Character3)->Load(_T("./Data/Image/Game/chara1.png"), 2, 2, 1, 96, 96);
	cImageResourceContainer::GetInstance()->GetElement(eImage_GameButton)->Load(_T("./Data/Image/Game/button.png"));
	cImageResourceContainer::GetInstance()->GetElement(eImage_PauseButton)->Load(_T("./Data/Image/Game/pause.png"));
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
	if (CheckHandleASyncLoad(cFontContainer::GetInstance()->GetElement(eFont_MainFont)) == FALSE) {
		DrawStringToHandle(SCREEN_WIDTH - GetDrawStringWidthToHandle(_T("Loading"), _tcslen(_T("Loading")), cFontContainer::GetInstance()->GetElement(eFont_MainFont)) - 16, SCREEN_HEIGHT - SCREEN_HEIGHT / 30 - 16, _T("Loading"), GetColor(0xFF, 0xFF, 0xFF), cFontContainer::GetInstance()->GetElement(eFont_MainFont));
	}
}