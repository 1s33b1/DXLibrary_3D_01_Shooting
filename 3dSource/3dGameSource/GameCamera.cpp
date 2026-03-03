#include "GameCamera.h"
#include "DxLib.h"
#include <math.h>

// コンストラクタ
GameCamera::GameCamera()
	: m_cameraPos(VGet(0.0f, 2500.0f, -2400.0f)),
	m_cameraTarget(VGet(0.0f, -300.0f, 0.0f)),
	m_roll(0.0f)
{
}

//デストラクタ
GameCamera::~GameCamera()
{
}

// 更新処理
void GameCamera::Update()
{
	// 左右キーでカメラの回転値を変更
	if (CheckHitKey(KEY_INPUT_LEFT) == 1)
	{
		m_cameraPos.x -= 10.0f; // カメラを下に移動
	}
	if (CheckHitKey(KEY_INPUT_RIGHT) == 1)
	{
		m_cameraPos.x += 10.0f; // カメラを上に移動
	}
	if (CheckHitKey(KEY_INPUT_UP) == 1) {
		m_cameraPos.y += 10.0f; // カメラを上に移動
	}
	if (CheckHitKey(KEY_INPUT_DOWN) == 1) {
		m_cameraPos.y -= 10.0f; // カメラを下に移動
	}

	// カメラ設定
	SetCameraPositionAndTargetAndUpVec(
		m_cameraPos,
		m_cameraTarget,
		VGet(sin(m_roll), cos(m_roll), 0.0f) // カメラを傾ける
	);
}
