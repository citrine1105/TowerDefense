#include "../../Header/Scene/Title.h"

cTitleScene::cTitleScene(iSceneChanger<eScene> *Changer) : cScene(Changer) {

}

void cTitleScene::Initialize() {
	mBackFade.SetPosition(255.0, 0.0);
	mMessageFade.SetPosition(0.0, 0.0);

	mBackFade.MoveToPoint(0.0, 0.0, 120, eEasing_Sine);
}

void cTitleScene::Finalize() {

}

void cTitleScene::Update() {
	cScene::Update();
	mBackFade.Update();
	mMessageFade.Update();
	double tValue;
	mMessageFade.GetPosition(&tValue, nullptr);

	if (tValue <= 0.0) {
		mMessageFade.MoveToPoint(255.0, 0.0, 45, eEasing_Sine);
	}
	else if (tValue >= 255.0) {
		mMessageFade.MoveToPoint(0.0, 0.0, 45, eEasing_Sine);
	}

	if (mKeyboard.GetInputState(KEY_INPUT_RETURN) == 1 ||
		mMouse.GetInputState(MOUSE_INPUT_LEFT) == 1) {
		pSceneChanger->ChangeScene(eScene_Game);	// �{�Ԃ̓��j���[��ʂֈڍs
	}
}

void cTitleScene::Draw() {
	//DrawString(0, 0, _T("TowerDefense�^�C�g�����"), GetColor(0xFF, 0xFF, 0xFF));
	//cScene::Draw();
	double tValue;
	std::tstring tVersion;	// �o�[�W�������

	tVersion = _T("Ver ");
	tVersion += VERSION_STRING;

	DrawExtendGraph(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, cImageResourceContainer::GetInstance()->GetElement(eImage_TitleBackground)->GetHandle(), FALSE);

	mMessageFade.GetPosition(&tValue, nullptr);
	DrawStringToHandle(SCREEN_WIDTH / 2 - GetDrawStringWidthToHandle(_T("Tower Defense"), _tcslen(_T("Tower Defense")), cFontContainer::GetInstance()->GetElement(eFont_MainFont)) / 2, SCREEN_HEIGHT / 5 * 2, _T("Tower Defense\n(�^�C�g���͉摜�ɍ����ւ��Ƃ���)"), GetColor(0xFF, 0xFF, 0xFF), cFontContainer::GetInstance()->GetElement(eFont_MainFont));
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, static_cast<int>(tValue));
	DrawStringToHandle(SCREEN_WIDTH / 2 - GetDrawStringWidthToHandle(_T("Press [Enter] Key or Mouse Click"), _tcslen(_T("Press [Enter] Key or Mouse Click")), cFontContainer::GetInstance()->GetElement(eFont_MainFont)) / 2, SCREEN_HEIGHT / 5 * 4, _T("Press [Enter] Key or Mouse Click"), GetColor(0xFF, 0xFF, 0xFF), cFontContainer::GetInstance()->GetElement(eFont_MainFont));
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
	DrawStringToHandle(SCREEN_WIDTH - GetDrawStringWidthToHandle(tVersion.c_str(), tVersion.size(), cFontContainer::GetInstance()->GetElement(eFont_MainFont)) - 16, SCREEN_HEIGHT - 40, tVersion.c_str(), GetColor(0xFF, 0xFF, 0xFF), cFontContainer::GetInstance()->GetElement(eFont_MainFont));

	mBackFade.GetPosition(&tValue, nullptr);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, static_cast<int>(tValue));
	DrawBox(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, GetColor(0x00, 0x00, 0x00), TRUE);	// �t�F�[�h�p
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
}