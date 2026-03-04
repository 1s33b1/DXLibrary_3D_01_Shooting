#include "Bullet.h"
#include "../GameParameter.h"
#include "DxLib.h"
#include "Player.h"

// コンストラクタ
// 引数：弾丸を描画し始めるときの初期位置をプレイヤーの位置から取得
Bullet::Bullet(int x, int y, int z)
	:bulletPos(VGet(x, y, z))
{
	color = GetColor(0, 255, 0); // 緑
	playerModel = Player().GetPlayerModel(); // プレイヤーのモデルを取得
	collResult = MV1CollCheck_Line(playerModel, 0, VGet(-1000.0f, 0.0f, 0.0f), VGet(1000.0f, 0.0f, 0.0f), -1); // プレイヤーのモデルと線の当たり判定を行う
}

// デストラクタ
Bullet::~Bullet()
{
}

// 更新処理
void Bullet::Update()
{
	//bulletPosy -= bulletSpeed; // 上方向へ進む

	collResult = MV1CollCheck_Line(Player().GetModelInfo(), 0, VGet(-1000.0f, 0.0f, 0.0f), VGet(1000.0f, 0.0f, 0.0f), -1);

	if (collResult.HitFlag == 1) {
		DrawFormatString(10, 10, GetColor(0, 0, 255), "HIT!");
	}
}

// 描画処理
void Bullet::Draw()
{
	DrawLine3D(VGet(-1000.0f, 0.0f, 0.0f), VGet(1000.0f, 0.0f, 0.0f), GetColor(255, 0, 0)); // X軸を赤で描画

	//DrawSphere3D(VGet(0.0f, 0.0f, -500.0f), 50.0f, 16, GetColor(255, 0, 0), color, TRUE); // プレイヤーの正面に球を描画)
}