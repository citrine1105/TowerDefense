#pragma once
#include "Include.h"

class cKeyboard : public iInitialization, iActivity {
protected:
	char mKeyState[256];
	unsigned AUTO_INT mKeyInputState[256];
public:
	cKeyboard();
	~cKeyboard();

	unsigned AUTO_INT GetInputState(const int Key);
	void ResetInputState();

	void Initialize();
	void Finalize();
	void Update();
	void Draw();
};