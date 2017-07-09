#pragma once
#include "Character.h"
#include "EnemyCharacter.h"

class cPlayerCharacter : public cCharacter {
public:
	cPlayerCharacter();
	~cPlayerCharacter();

	//void SetTarget(cEnemyCharacter *Character);

	void Initialize() override;
	void Initialize(const eCharacterType Type, const int Life, const int Attack, const int Defense, const double Speed, const int AttackInverval) override;
	void Draw() override;
};