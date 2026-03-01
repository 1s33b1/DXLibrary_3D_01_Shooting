#include "GameCamera.h"
#include "DxLib.h"
#include <math.h>

// コンストラクタ
GameCamera::GameCamera()
{

}

//デストラクタ
GameCamera::~GameCamera()
{

}

// 更新処理
void GameCamera::Update()
{
	float Roll = 0; // カメラの回転値

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
}
