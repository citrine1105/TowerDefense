#pragma once
#include "Character.h"
#include "PlayerCharacter.h"

class cEnemyCharacter : public cCharacter {
public:
	cEnemyCharacter();
	~cEnemyCharacter();

	//void SetTarget(cPlayerCharacter *Character);

	void Initialize(const eCharacterType Type, const int Life, const int Attack, const int Defense, const double Speed, const int AttackInverval) override;
	void Draw() override;
};