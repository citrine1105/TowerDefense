#pragma once
#include "Sprite.h"
#include "FontContainer.h"

class cTower : public cSprite {
protected:
	int mLife;
	int mMaxLife;
	//int mDefense;
public:
	cTower();
	~cTower();

	void Damage(const int Damage);
	void SetLife(const int Life);
	int GetLife();

	void Initialize() override;
	void Finalize() override;
	void Update() override;
	virtual void Draw() override;
};