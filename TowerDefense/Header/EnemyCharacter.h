#pragma once
#include "Character.h"

class cEnemyCharacter : public cCharacter {
public:
	cEnemyCharacter();
	~cEnemyCharacter();

	void Initialize(const eCharacterType Type, const int Life, const int Attack, const int Defense, const double Speed) override;
	void Draw() override;
};