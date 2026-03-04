#include "Player.h"
#include "DxLib.h"

/// <summary>
// 
/// </summary>

// コンストラクタ
Player::Player()
	:m_playerPos(VGet(0.0f, 0.0f, 0.0f)),
	m_playerSpeed(5.0f)
{
	m_playerModel = MV1LoadModel("Model/CraneoFBX.mv1");// モデルをメモリにロード
	modelInfo = MV1SetupCollInfo(m_playerModel,0,8,8,8); // モデルの当たり判定を設定
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
	MV1SetPosition(m_playerModel, m_playerPos); // モデルの位置を更新
	MV1RefreshCollInfo(m_playerModel); // 当たり判定を更新
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
	if(CheckHitKey(KEY_INPUT_W)){
		m_playerPos.z += m_playerSpeed; // 前に移動
	}
	// Sキー、下矢印キー
	if(CheckHitKey(KEY_INPUT_S)){
		m_playerPos.z -= m_playerSpeed; // 後ろに移動
	}
	// Aキー、左矢印キー
	if(CheckHitKey(KEY_INPUT_A)){
		m_playerPos.x -= m_playerSpeed; // 左に移動
	}
	// Dキー、右矢印キー
	if(CheckHitKey(KEY_INPUT_D)){
		m_playerPos.x += m_playerSpeed; // 右に移動
	}
}

