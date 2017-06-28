#include "../Header/Include.h"
#include "../Header/SceneManager.h"

int Game_Init();	 // アプリケーション初期化処理

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow) {
	if (Game_Init() != 0) {
		MessageBox(GetMainWindowHandle(), _T("初期化に失敗しました"), CAPTION_STRING, MB_OK | MB_ICONERROR);
	}
	SetMouseDispFlag(TRUE);
	SetDrawScreen(DX_SCREEN_BACK);
	SetDrawMode(DX_DRAWMODE_BILINEAR);

	cSceneManager scene;
	scene.Initialize();

	while (ProcessMessage() == 0 && ClearDrawScreen() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0) {
		scene.Update();
		scene.Draw();
		ScreenFlip();
	}

	scene.Finalize();

	DxLib_End();

	return 0;
}

int Game_Init() {
#ifdef _DEBUG
	SetOutApplicationLogValidFlag(TRUE);		// デバッグモード時はログを出力
#else
	SetOutApplicationLogValidFlag(FALSE);	// リリースモード時はログを出力しない
#endif // _DEBUG
	SetUseDXArchiveFlag(TRUE);	// DXアーカイブを有効に
	SetDXArchiveKeyString(DX_ARCHIVE_KEY_STRING);	// DXアーカイブキー
	SetMultiThreadFlag(TRUE);	// マルチスレッド動作有効
	SetAlwaysRunFlag(TRUE);	// 非アクティブ時も動作
	SetGraphMode(1280, 720, 32);	// テスト
	if (MessageBox(GetMainWindowHandle(), _T("フルスクリーンモードで起動しますか?"), CAPTION_STRING, MB_YESNO | MB_ICONQUESTION) == IDYES) {
		ChangeWindowMode(FALSE);
	}
	else {
		ChangeWindowMode(TRUE);
	}
	SetMainWindowText(CAPTION_STRING);	// タイトルバー文字列を設定
	SetFullScreenResolutionMode(DX_FSRESOLUTIONMODE_NATIVE);		// フルスクリーン時の挙動を設定
	SetUseDirect3DVersion(DX_DIRECT3D_9EX);	// Direct3D 9Exを使用する
	//SetUseASyncLoadFlag(TRUE);	// 非同期読み込みを有効に
	if (DxLib_Init() != 0) {
		return -1;
	}	// DXライブラリ初期化

	return 0;
}