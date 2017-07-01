#pragma once
#include "Include.h"
#include "SceneChanger.h"
#include "Keyboard.h"
#include "Mouse.h"

enum eScene {
	eScene_Load,
	eScene_Logo,
	eScene_Title,
	eScene_Menu,
	eScene_Game,

	eScene_None
};

class cScene : public iInitialization, iActivity {
protected:
	iSceneChanger<eScene> *pSceneChanger;	// シーン切り替えインターフェース

	static cKeyboard mKeyboard;	// キーボード
	static cMouse mMouse;		// マウス

	static int mMainFont;
public:
	cScene(iSceneChanger<eScene> *Changer);
	virtual ~cScene();
	virtual void Initialize() override;
	virtual void Finalize() override;
	virtual void Update() override;
	virtual void Draw() override;
};