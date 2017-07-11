#pragma once
#include "../Scene.h"
#include "../Sprite.h"

class cMenuScene : public cScene {
protected:
	cSprite mColumn;
	cSprite Menubutton[3];
public:
	cMenuScene(iSceneChanger<eScene> *Changer);
	void Initialize() override;
	void Finalize() override;
	void Update() override;
	void Draw() override;
};