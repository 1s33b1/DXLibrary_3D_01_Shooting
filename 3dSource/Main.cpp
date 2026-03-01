/// <summary>
/// シューティング
/// 作成日：2026/2/27
/// メイン関数
/// フリーサイトでダウンロードしたものをDXLibraryのツールを使ってmv1形式に変換して、やりたい。
/// </summary>

#include "DxLib.h"
#include "math.h"
#include "GameParameter.h"
#include "Player.h"
#include <memory>

// 初期化処理
static void Initialize()
{

}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	float Roll = 0;

	SetGraphMode(ScreenSettings::screenWidth, ScreenSettings::screenHeight, 30); // 画面のサイズを決定
	SetWaitVSyncFlag(TRUE); // これを付けるとヌルヌルになりすぎて動作が何もかも早くなるからいったんなしで。
	// DXライブラリ初期化処理
	if (DxLib_Init() == -1) return -1;
	SetDrawScreen(DX_SCREEN_BACK);
	SetMouseDispFlag(FALSE); // マウスカーソルを非表示

	auto m_Player =  std::make_unique<Player>(); // プレイヤーの描画

	// メインのループ処理
	//----------------------------------------------------------------
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		ClearDrawScreen(); // 画面をまっさらに

		m_Player->Update(); // プレイヤーの更新
		m_Player->Draw(); // プレイヤーの描画

		// 左右キーでカメラの回転値を変更
		if (CheckHitKey(KEY_INPUT_LEFT) == 1)
		{
			Roll -= DX_PI_F / 60.0f;
		}
		if (CheckHitKey(KEY_INPUT_RIGHT) == 1)
		{
			Roll += DX_PI_F / 60.0f;
		}

		// カメラ設定
		SetCameraPositionAndTargetAndUpVec(
			VGet(0.0f, 400.0f, -1500.0f),
			VGet(0.0f, 0.0f, 0.0f),
			VGet(sin(Roll), cos(Roll), 0.0f) // カメラを傾ける
		);

		DrawLine3D(VGet(-1000.0f, 0.0f, 0.0f), VGet(1000.0f, 0.0f, 0.0f), GetColor(255, 0, 0)); // X軸を赤で描画
		ScreenFlip();    // 画面を更新して、少し休む	
	}


	///----------------------------------------------------------------
	/// 終了処理
	
	DxLib_End();				// ＤＸライブラリ使用の終了処理
	return 0;				// ソフトの終了 
}
