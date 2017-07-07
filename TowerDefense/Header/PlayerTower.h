#pragma once
#include "Tower.h"

class cPlayerTower : public cTower {
public:
	cPlayerTower();
	~cPlayerTower();

	void Draw() override;
};