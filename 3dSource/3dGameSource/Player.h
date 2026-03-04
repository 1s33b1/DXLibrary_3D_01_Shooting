#pragma once
#include "DxLib.h"

class Player
{
public:
	Player();
	~Player();
	void Update();
	void Draw();
	void Move(); // プレイヤーを移動させる関数
	VECTOR GetPosition() const { return m_playerPos; } // プレイヤーの位置を取得するためのインライン関数
	int GetModelInfo() const { return modelInfo; } // モデルの当たり判定情報を取得するためのインライン関数
	int GetPlayerModel() const { return m_playerModel; }
private:
	int modelInfo;
	int m_playerModel; // プレイヤーのモデル
	float m_playerSpeed; // プレイヤーの移動速度
	VECTOR m_playerPos; // プレイヤーの位置
};
 