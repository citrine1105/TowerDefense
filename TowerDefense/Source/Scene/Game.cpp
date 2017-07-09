#include "../../Header/Scene/Game.h"

cGameScene::cGameScene(iSceneChanger<eScene> *Changer) : cScene(Changer) {

}

void cGameScene::Initialize() {
	for (int i = 0; i < 5; i++) {
		mButton[i].SetCollisionRange(96.0, 96.0);	// 各種ボタンの当たり判定設定
		mPauseButton.SetCollisionRange(64.0, 64.0);
	}

	for (int i = 0; i < 24; i++) {
		mTree[i].SetPosition(GetRand(SCREEN_WIDTH / 24) + SCREEN_WIDTH / 24 * i, SCREEN_HEIGHT * 23 / 36);	// 木をランダム配置
	}

	mPlayerTower.SetPosition(SCREEN_WIDTH * 6 / 7, SCREEN_HEIGHT * 49 / 72);		// プレイヤー側のタワー位置設定
	mPlayerTower.SetLife(10000);			// プレイヤー側のタワー体力設定
	mEnemyTower.SetPosition(SCREEN_WIDTH / 7, SCREEN_HEIGHT * 49 / 72);		// 敵側のタワー位置設定
	mEnemyTower.SetLife(10000);			// 敵側のタワー体力設定

	mButton[0].SetPosition(SCREEN_WIDTH / 2.0 + (-96.0 - 32.0) * 2.0, SCREEN_HEIGHT - 48.0 - 24.0);	// キャラクター投入ボタンの配置
	mButton[1].SetPosition(SCREEN_WIDTH / 2.0 + (-96.0 - 32.0) * 1.0, SCREEN_HEIGHT - 48.0 - 24.0);
	mButton[2].SetPosition(SCREEN_WIDTH / 2.0 + (-96.0 - 32.0) * 0.0, SCREEN_HEIGHT - 48.0 - 24.0);
	mButton[3].SetPosition(SCREEN_WIDTH / 2.0 - (-96.0 - 32.0) * 1.0, SCREEN_HEIGHT - 48.0 - 24.0);
	mButton[4].SetPosition(SCREEN_WIDTH / 2.0 - (-96.0 - 32.0) * 2.0, SCREEN_HEIGHT - 48.0 - 24.0);

	mPauseButton.SetPosition(32.0 + 36.0, 32.0 + 24.0);	// ポーズボタンの配置

	fPauseFlag = false;
}

void cGameScene::Finalize() {

}

void cGameScene::Update() {
	auto tPlayerCharacterIterator = mPlayerCharacter.begin();	// プレイヤーキャラのイテレータ
	auto tEnemyCharacterIterator = mEnemyCharacter.begin();		// 敵キャラのイテレータ
	int i;
	cScene::Update();	// キーボード・マウスの入力取得

	if (mPauseButton.GetCollisionFlag(mMouse.GetSprite()) && mMouse.GetInputState(MOUSE_INPUT_LEFT) == 1) {	// ポーズボタンが押されたら
		fPauseFlag = !fPauseFlag;	// ポーズ状態の切り替え
	}

	if (!fPauseFlag) {	// ポーズ状態でなければ
		for (int i = 0; i < 5; i++) {
			if (mButton[i].GetCollisionFlag(mMouse.GetSprite())) {	// ボタンとマウスが接触していて
				if (mMouse.GetInputState(MOUSE_INPUT_LEFT) == 1) {	// 左ボタンが押されたら
					if (i == 0) {
						cPlayerCharacter *tCh = new cPlayerCharacter;
						tCh->Initialize(static_cast<eCharacterType>(GetRand(eChara_None - 1)), 100, 10, 5, (GetRand(20) + 5) / 10.0, 18);
						mPlayerCharacter.push_back(*tCh);	// プレイヤーキャラを追加
						delete tCh;
					}
					else {
						cEnemyCharacter *tCh = new cEnemyCharacter;
						tCh->Initialize(static_cast<eCharacterType>(GetRand(eChara_None - 1)), (GetRand(10) + 5) * 100, 50, 5, (GetRand(20) + 5) / 10.0, 18);
						mEnemyCharacter.push_back(*tCh);		// 敵キャラを追加
						delete tCh;
					}
				}
			}
		}

		for (auto& i : mPlayerCharacter) {	// プレイヤーキャラの更新
			i.Update();
		}
		for (auto& i : mEnemyCharacter) {	// 敵キャラの更新
			i.Update();
		}

		for (auto& i : mPlayerCharacter) {
			if (i.GetCollisionFlag(&mEnemyTower) &&	// プレイヤーキャラと敵タワーが接触して
				i.GetTarget() == nullptr) {			// なおかつプレイヤーキャラの狙いがない場合
				i.SetTarget(&mEnemyTower);			// プレイヤーキャラの攻撃対象を敵タワーに設定
			}
		}

		for (auto& i : mEnemyCharacter) {
			if (i.GetCollisionFlag(&mPlayerTower) &&		// 敵キャラとプレイヤータワーが接触して
				i.GetTarget() == nullptr) {				// なおかつ敵キャラの狙いがない場合
				i.SetTarget(&mPlayerTower);				// 敵キャラの攻撃対象をプレイヤータワーに設定
			}
		}

		for (auto& i : mPlayerCharacter) {
			for (auto& j : mEnemyCharacter) {
				if (i.GetCollisionFlag(&j)) {	// プレイヤーキャラと敵キャラが接触している場合
					if (i.GetTarget() == &mEnemyTower && j.GetTarget() == nullptr) {		// プレイヤーキャラの攻撃対象が敵タワーの場合
						j.SetTarget(&i);		// 敵キャラの攻撃対象をプレイヤーキャラに設定
					}
					else if (j.GetTarget() == &mPlayerTower && i.GetTarget() == nullptr) {	// 敵キャラの攻撃対象がプレイヤータワーの場合
						i.SetTarget(&j);		// プレイヤーキャラの攻撃対象を敵キャラに設定
					}
					else if (i.GetTarget() == nullptr && j.GetTarget() == nullptr) {		// どちらも攻撃対象がいない場合
						i.SetTarget(&j);		// 互いを攻撃対象に設定
						j.SetTarget(&i);
					}
				}
			}
		}

		for (tPlayerCharacterIterator = mPlayerCharacter.begin();
			tPlayerCharacterIterator != mPlayerCharacter.end();) {
			if (!tPlayerCharacterIterator->GetActiveFlag()) {	// プレイヤーキャラが無効になった場合
				tPlayerCharacterIterator = mPlayerCharacter.erase(tPlayerCharacterIterator);		// 要素を消去
				continue;
			}
			++tPlayerCharacterIterator;
		}

		for (tEnemyCharacterIterator = mEnemyCharacter.begin();
			tEnemyCharacterIterator != mEnemyCharacter.end();) {
			if (!tEnemyCharacterIterator->GetActiveFlag()) {		// 敵キャラが無効になった場合
				tEnemyCharacterIterator = mEnemyCharacter.erase(tEnemyCharacterIterator);	// 要素を消去
				continue;
			}
			++tEnemyCharacterIterator;
		}
	}
}

void cGameScene::Draw() {
	double tPosX, tPosY;
	std::tstring tAreaName;
	std::tstring tMoney;

	tAreaName = _T("進捗ダメです");
	tMoney = std::to_tstring(8101919);
	tMoney += _T("G");

	DrawExtendGraph(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, cImageResourceContainer::GetInstance()->GetElement(eImage_GameBackBase)->GetHandle(), FALSE);		// 背景描画
	DrawExtendGraph(0, 0 - SCREEN_HEIGHT / 4, SCREEN_WIDTH, SCREEN_HEIGHT - SCREEN_HEIGHT / 4, cImageResourceContainer::GetInstance()->GetElement(eImage_GameBackCloud)->GetHandle(), TRUE);		// 雲描画
	for (int i = 0; i < 24; i++) {
		mTree[i].GetPosition(&tPosX, &tPosY);
		DrawRotaGraph(tPosX, tPosY, 1.0, 0.0, cImageResourceContainer::GetInstance()->GetElement(eImage_GameBackTree)->GetHandle(), TRUE);	// 木描画
	}

	mPlayerTower.Draw();		// タワー描画
	mEnemyTower.Draw();

	for (int i = 0; i < 5; i++) {
		mButton[i].GetPosition(&tPosX, &tPosY);
		DrawGraph(static_cast<int>(tPosX - 48.0), static_cast<int>(tPosY - 48.0), cImageResourceContainer::GetInstance()->GetElement(eImage_GameButton)->GetHandle(), TRUE);		// キャラ投入ボタン描画
	}

	DrawStringToHandle(36 + 64 + 32, 24 + 6, tAreaName.c_str(), GetColor(0xFF, 0xFF, 0xFF), cFontContainer::GetInstance()->GetElement(eFont_GameMoneyFont), GetColor(0x77, 0x4D, 0x28));		// エリア名描画
	DrawStringToHandle(SCREEN_WIDTH - GetDrawStringWidthToHandle(tMoney.c_str(), tMoney.size(), cFontContainer::GetInstance()->GetElement(eFont_GameMoneyFont)) - 36, 24, tMoney.c_str(), GetColor(0xF2, 0xCD, 0x54), cFontContainer::GetInstance()->GetElement(eFont_GameMoneyFont), GetColor(0x60, 0x39, 0x16));	// 残りゴールド描画

	for (auto& i : mEnemyCharacter) {	// 敵キャラ描画
		i.Draw();
	}
	for (auto& i : mPlayerCharacter) {	// プレイヤー描画
		i.Draw();
	}

	if (fPauseFlag) {
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
		DrawBox(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, GetColor(0x00, 0x00, 0x00), TRUE);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
		DrawStringToHandle(SCREEN_WIDTH / 2 - GetDrawStringWidthToHandle(_T("Pause"), _tcsclen(_T("Pause")), cFontContainer::GetInstance()->GetElement(eFont_GameMoneyFont)) / 2, SCREEN_HEIGHT / 2 - 64, _T("Pause"), GetColor(0xFF, 0xFF, 0xFF), cFontContainer::GetInstance()->GetElement(eFont_GameMoneyFont), GetColor(0x77, 0x4D, 0x28));
	}

	mPauseButton.GetPosition(&tPosX, &tPosY);
	DrawGraph(static_cast<int>(tPosX - 32.0), static_cast<int>(tPosY - 32.0), cImageResourceContainer::GetInstance()->GetElement(eImage_PauseButton)->GetHandle(), TRUE);	// ポーズボタン描画
}