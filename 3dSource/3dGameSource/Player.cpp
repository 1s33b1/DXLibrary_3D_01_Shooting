#include "Player.h"
#include "DxLib.h"

/// <summary>
// 
/// </summary>

// コンストラクタ
Player::Player()
	:m_playerPosition(VGet(0.0f, 0.0f, 0.0f)) // プレイヤーの初期位置を設定
{
	m_playerModel = MV1LoadModel("Model/CraneoFBX.mv1");// モデルをメモリにロード
}

// デストラクタ
Player::~Player()
{
	MV1DeleteModel(m_playerModel); // モデルの解放
}

// 更新処理
void Player::Update()
{
	Move();
	MV1SetPosition(m_playerModel, m_playerPosition); // モデルの位置を更新
}

// 描画処理
void Player::Draw()
{
	MV1DrawModel(m_playerModel); // モデルを描く
}

// プレイヤーの移動処理
void Player::Move()
{
	// Wキー、上矢印キー
	if(CheckHitKey(KEY_INPUT_W) || CheckHitKey(KEY_INPUT_UP)){
		m_playerPosition.z += 0.1f; // 前に移動
	}
	// Sキー、下矢印キー
	if(CheckHitKey(KEY_INPUT_S) || CheckHitKey(KEY_INPUT_DOWN)){
		m_playerPosition.z -= 0.1f; // 後ろに移動
	}
	// Aキー、左矢印キー
	if(CheckHitKey(KEY_INPUT_A) || CheckHitKey(KEY_INPUT_LEFT)){
		m_playerPosition.x -= 0.1f; // 左に移動
	}
	// Dキー、右矢印キー
	if(CheckHitKey(KEY_INPUT_D) || CheckHitKey(KEY_INPUT_RIGHT)){
		m_playerPosition.x += 0.1f; // 右に移動
	}
}

