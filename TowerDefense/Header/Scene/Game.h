﻿#pragma once
#include "../Scene.h"
#include "../PlayerCharacter.h"
#include "../EnemyCharacter.h"
#include "../PlayerTower.h"
#include "../EnemyTower.h"

class cGameScene : public cScene {
protected:
	cSprite mButton[5];
	cSprite mPauseButton;

	cSprite mTree[24];

	std::list<cPlayerCharacter> mPlayerCharacter;
	std::list<cEnemyCharacter> mEnemyCharacter;
	cPlayerTower mPlayerTower;
	cEnemyTower mEnemyTower;

	bool fPauseFlag;
public:
	cGameScene(iSceneChanger<eScene> *Changer);
	void Initialize() override;
	void Finalize() override;
	void Update() override;
	void Draw() override;
};