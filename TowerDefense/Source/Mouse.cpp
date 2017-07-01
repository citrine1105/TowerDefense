#include "../Header/Mouse.h"

cMouse::cMouse() {
	this->Initialize();
}

cMouse::~cMouse() {
	this->Finalize();
}

void cMouse::GetPosition(int *PositionX, int *PositionY) {
	GetMousePoint(PositionX, PositionY);
}

unsigned AUTO_INT cMouse::GetInputState(const int Button) {
	switch (Button) {
	case MOUSE_INPUT_LEFT:
		return mInputState[0];
		break;
	case MOUSE_INPUT_RIGHT:
		return mInputState[1];
		break;
	case MOUSE_INPUT_MIDDLE:
		return mInputState[2];
		break;
	default:
		return 0;
		break;
	}
}

void cMouse::SetPosition(const int PositionX, const int PositionY) {
	SetMousePoint(PositionX, PositionY);
}

void cMouse::SetPosition(cSprite *Sprite) {
	double tX, tY;
	Sprite->GetPosition(&tX, &tY);
	SetMousePoint(static_cast<int>(tX), static_cast<int>(tY));
}

cSprite* cMouse::GetSprite() {
	return &mSprite;
}

void cMouse::ResetInputState() {
	for (auto i : mInputState) {
		i = 0;
	}
}

void cMouse::Initialize() {
	this->ResetInputState();
	mSprite.Initialize();
	mSprite.SetCollisionRange(1.0, 1.0);
}

void cMouse::Finalize() {
	this->ResetInputState();
	mSprite.Finalize();
}

void cMouse::Update() {
	int tX, tY;
	this->GetPosition(&tX, &tY);
	if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) {
		++mInputState[0];
	}
	else {
		mInputState[0] = 0;
	}

	if ((GetMouseInput() & MOUSE_INPUT_RIGHT) != 0) {
		++mInputState[1];
	}
	else {
		mInputState[1] = 0;
	}

	if ((GetMouseInput() & MOUSE_INPUT_MIDDLE) != 0) {
		++mInputState[2];
	}
	else {
		mInputState[2] = 0;
	}
	mSprite.SetPosition(static_cast<double>(tX), static_cast<double>(tY));
}

void cMouse::Draw() {
	int tX, tY;
	this->GetPosition(&tX, &tY);
	DrawFormatString(0, 0, GetColor(0xFF, 0xFF, 0xFF), _T("X:%d Y:%d"), tX, tY);
	for (int i = 0; i < 3; i++) {
		DrawFormatString(0, 18 * (i + 1), GetColor(0xFF, 0xFF, 0xFF), _T("%u"), mInputState[i]);
	}
	DrawLine(tX - 32, tY, tX + 32, tY, GetColor(0xFF, 0xFF, 0xFF));
	DrawLine(tX, tY - 32, tX, tY + 32, GetColor(0xFF, 0xFF, 0xFF));
}