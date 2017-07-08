#pragma once
#include "Character.h"

class cTower : public cCharacter {
public:
	cTower();
	~cTower();

	void SetLife(const int Life);

	virtual void Initialize() override;
	virtual void Draw() override;
};