﻿#include "../Header/Sprite.h"

cSprite::cSprite() {
	this->Initialize();
}

cSprite::~cSprite() {
	this->Finalize();
}

void cSprite::Move() {
	double tPositionX, tPositionY;
	mMoveVector.GetEndPoint(&tPositionX, &tPositionY);
	//this->MoveToPoint(tPositionX, tPositionY, 1);
	mPositionX += tPositionX;
	mPositionY += tPositionY;
}

void cSprite::MoveToPoint(const double PositionX, const double PositionY, const int MoveTime, const eEasingType MoveType, const eEasingFunction EasingFunction) {
	mMoveVector.SetStartPoint(mPositionX, mPositionY);
	mMoveVector.SetEndPoint(PositionX, PositionY);
	mMoveTime = MoveTime > 0 ? MoveTime : 1;
	mMoveType = MoveType;
	mEaseFunc = EasingFunction;
	mDelayTimer.Initialize();
	mDelayTimer.SetValue(mMoveTime);
	mDelayTimer.SetCountMode(eCountMode_CountDown);
	mDelayTimer.Start();
}

void cSprite::SetPosition(const double PositionX, const double PositionY) {
	mPositionX = PositionX;
	mPositionY = PositionY;
	mMoveVector.SetStartPoint(mPositionX, mPositionY);
	mCollisionVector.SetStartPoint(mPositionX, mPositionY);
}

void cSprite::SetCollisionRange(const double RangeX, const double RangeY, const eCollisionType CollisionType) {
	mCollisionRangeX = RangeX;
	mCollisionRangeY = RangeY;
	mCollisionType = CollisionType;
}

void cSprite::GetPosition(double *PositionX, double *PositionY) {
	if (PositionX != nullptr) {
		*PositionX = mPositionX;
	}
	if (PositionY != nullptr) {
		*PositionY = mPositionY;
	}
}

void cSprite::GetCollisionRange(double *RangeX, double *RangeY) {
	if (RangeX != nullptr) {
		*RangeX = mCollisionRangeX;
	}
	if (RangeY != nullptr) {
		*RangeY = mCollisionRangeY;
	}
}

cVector2D* cSprite::GetMoveVectorPointer() {
	return &mMoveVector;
}

cVector2D* cSprite::GetCollisionVectorPointer() {
	return &mCollisionVector;
}

bool cSprite::GetCollisionFlag(cSprite *Sprite) {
	// 傾きのない矩形同士の判定だけ実装
	struct tsPoint {
		double Top;
		double Bottom;
		double Left;
		double Right;
	};

	tsPoint tPoint[2];
	double tPosX, tPosY, tRangeX, tRangeY;
	Sprite->GetPosition(&tPosX, &tPosY);
	Sprite->GetCollisionRange(&tRangeX, &tRangeY);

	if (mCollisionRangeX <= 0.0 ||
		mCollisionRangeY <= 0.0 ||
		tRangeX <= 0.0 ||
		tRangeY <= 0.0) {
		return false;
	}

	tPoint[0].Top = mPositionY - mCollisionRangeY / 2.0;
	tPoint[0].Bottom = mPositionY + mCollisionRangeY / 2.0;
	tPoint[0].Left = mPositionX - mCollisionRangeX / 2.0;
	tPoint[0].Right = mPositionX + mCollisionRangeX / 2.0;

	tPoint[1].Top = tPosY - tRangeY / 2.0;
	tPoint[1].Bottom = tPosY + tRangeY / 2.0;
	tPoint[1].Left = tPosX - tRangeX / 2.0;
	tPoint[1].Right = tPosX + tRangeX / 2.0;

	if ((tPoint[0].Top <= tPoint[1].Bottom && tPoint[0].Bottom >= tPoint[1].Top) &&
		(tPoint[0].Left <= tPoint[1].Right && tPoint[0].Right >= tPoint[1].Left)) {
		return true;
	}
	else {
		return false;
	}
}

void cSprite::Initialize() {
	this->SetPosition(0.0, 0.0);
	mCollisionRangeX = 0.0;
	mCollisionRangeY = 0.0;
	mMoveVector.SetPolarForm(0.0, 0.0);
	mCollisionVector.SetPolarForm(0.0, 1.0);
	mDelayTimer.Initialize();
	mEaseFunc = eEasingFunction_In;
	mMoveType = eEasing_Linear;
	mMoveTime = 0;
}

void cSprite::Finalize() {
	this->SetPosition(0.0, 0.0);
	mCollisionRangeX = 0.0;
	mCollisionRangeY = 0.0;
	mMoveVector.SetPolarForm(0.0, 0.0);
	mCollisionVector.SetPolarForm(0.0, 1.0);
	mDelayTimer.Finalize();
	mEaseFunc = eEasingFunction_In;
	mMoveType = eEasing_Linear;
	mMoveTime = 0;
}

void cSprite::Update() {
	mDelayTimer.Update();
	if (mDelayTimer.GetActiveFlag()) {
		cVector2D tVector = mMoveVector;
		double tPositionX, tPositionY;
		tVector *= cEasing::GetInstance()->GetEase(mEaseFunc, mMoveType, 1.0 - static_cast<double>(mDelayTimer.GetValue()) / static_cast<double>(mMoveTime), 1.0);
		tVector.GetEndPoint(&tPositionX, &tPositionY);
		mPositionX = tPositionX;
		mPositionY = tPositionY;
	}
	if (mDelayTimer.GetValue() <= 0) {
		mDelayTimer.Stop();
	}
	mCollisionVector.SetStartPoint(mPositionX, mPositionY);
}

void cSprite::Draw() {
	double tPositionX, tPositionY;
	mCollisionVector.GetEndPoint(&tPositionX, &tPositionY);
	DrawCircleAA(mPositionX, mPositionY, 20.0, 24, GetColor(0xFF, 0xFF, 0xFF));
	//DrawLine(mPositionX, mPositionY, tPositionX, tPositionY, GetColor(0x00, 0x9F, 0x00));
	//mMoveVector.Draw();
}