#pragma once
#include "../Scene.h"
#include "../Sprite.h"

class cTitleScene : public cScene {
private:
	cSprite mBackFade;
	cSprite mMessageFade;
public:
	cTitleScene(iSceneChanger<eScene> *Changer);
	void Initialize() override;
	void Finalize() override;
	void Update() override;
	void Draw() override;
};