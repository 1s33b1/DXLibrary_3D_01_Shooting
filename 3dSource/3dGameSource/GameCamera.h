#pragma once
#include "DxLib.h"

class GameCamera
{
public:
	GameCamera();
	~GameCamera();
	void Update();

private:
	VECTOR m_cameraPos; // カメラの位置
	VECTOR m_cameraTarget; // カメラの注視点(見ている座標)
	float m_roll; // カメラの回転値
};
