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
private:
	int m_playerModel; // プレイヤーのモデル
	VECTOR m_playerPosition; // プレイヤーの位置
};
 