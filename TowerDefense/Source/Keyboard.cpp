#include "../Header/Keyboard.h"

cKeyboard::cKeyboard() {
	this->Initialize();
}

cKeyboard::~cKeyboard() {
	this->Finalize();
}

unsigned AUTO_INT cKeyboard::GetInputState(const int Key) {
	return mKeyInputState[Key];
}

void cKeyboard::ResetInputState() {
	//for (int i = 0; i < 256; i++) {
	//	mKeyState[i] = 0;
	//	mKeyInputState[i] = 0;
	//}
	for (auto i : mKeyState) {
		i = 0;
	}
	for (auto i : mKeyInputState) {
		i = 0;
	}
}

void cKeyboard::Initialize() {
	this->ResetInputState();
}

void cKeyboard::Finalize() {
	this->ResetInputState();
}

void cKeyboard::Update() {
	GetHitKeyStateAll(mKeyState);
	for (int i = 0; i < 256; i++) {
		if (mKeyState[i] != 0) {
			++mKeyInputState[i];
		}
		else {
			mKeyInputState[i] = 0;
		}
	}
}

void cKeyboard::Draw() {
	for (int i = 0; i < 256; i++) {
		DrawFormatString(0, 18 * i, GetColor(0xFF, 0xFF, 0xFF), _T("%d"), mKeyInputState[i]);
	}
}