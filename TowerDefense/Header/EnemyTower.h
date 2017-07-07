#pragma once
#include "Tower.h"

class cEnemyTower : public cTower {
public:
	cEnemyTower();
	~cEnemyTower();

	void Draw() override;
};