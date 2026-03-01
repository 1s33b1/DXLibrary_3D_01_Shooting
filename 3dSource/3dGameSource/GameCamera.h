#pragma once
class GameCamera
{
public:
	GameCamera();
	~GameCamera();
	void Update();

private:
	VECTOR m_cameraPos;
};
