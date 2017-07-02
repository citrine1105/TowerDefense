#pragma once
#include "../Scene.h"
#include "../Character.h"

class cGameScene : public cScene {
protected:
	cSprite mButton[5];
	cSprite mPauseButton;

	std::vector<cCharacter> mCharacter;
public:
	cGameScene(iSceneChanger<eScene> *Changer);
	void Initialize() override;
	void Finalize() override;
	void Update() override;
	void Draw() override;
};