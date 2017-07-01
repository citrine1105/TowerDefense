#include "../Header/Scene.h"

cKeyboard cScene::mKeyboard;
cMouse cScene::mMouse;

int cScene::mMainFont;

cScene::cScene(iSceneChanger<eScene> *Changer) {
	pSceneChanger = Changer;
}

cScene::~cScene() {

}

void cScene::Initialize() {

}

void cScene::Finalize() {
	DeleteFontToHandle(mMainFont);
}

void cScene::Update() {
	mKeyboard.Update();
	mMouse.Update();
}

void cScene::Draw() {
	//mKeyboard.Draw();
	mMouse.Draw();
}