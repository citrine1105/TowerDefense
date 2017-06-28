#include "../../Header/Scene/Title.h"

cTitleScene::cTitleScene(iSceneChanger<eScene> *Changer) : cScene(Changer) {

}

void cTitleScene::Initialize() {

}

void cTitleScene::Finalize() {

}

void cTitleScene::Update() {
	cScene::Update();
}

void cTitleScene::Draw() {
	DrawString(0, 0, _T("ƒ^ƒCƒgƒ‹‰æ–ÊÀÞÖ°"), GetColor(0xFF, 0xFF, 0xFF));
}