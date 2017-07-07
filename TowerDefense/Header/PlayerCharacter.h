#pragma once
#include "Character.h"

class cPlayerCharacter : public cCharacter {
protected:
	cCharacter *pTargetCharacter;
public:
	cPlayerCharacter();
	~cPlayerCharacter();

	void Initialize() override;
	void Initialize(const eCharacterType Type, const int Life, const int Attack, const int Defense, const double Speed);
	void Draw() override;
};