#pragma once
#include "Include.h"
#include "Sprite.h"

class cMouse : public iInitialization, iActivity {
protected:
	unsigned AUTO_INT mInputState[3];
	cSprite mSprite;
public:
	cMouse();
	~cMouse();

	void GetPosition(int *PositionX, int *PositionY);
	unsigned AUTO_INT GetInputState(const int Button);
	cSprite* GetSprite();
	void SetPosition(const int PositionX, const int PositionY);
	void SetPosition(cSprite *Sprite);
	void ResetInputState();

	void Initialize() override;
	void Finalize() override;
	void Update() override;
	void Draw() override;
};