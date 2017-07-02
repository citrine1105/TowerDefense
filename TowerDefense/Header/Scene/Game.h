#pragma once
#include "../Scene.h"

class cGameScene : public cScene {
protected:
	cSprite mButton[5];
	cSprite mPauseButton;
public:
	cGameScene(iSceneChanger<eScene> *Changer);
	void Initialize() override;
	void Finalize() override;
	void Update() override;
	void Draw() override;
};