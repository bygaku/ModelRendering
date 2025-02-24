#pragma once

/// @brief 定義
class Player;

/// @brief カメラ
class Camera
{
public:
	Camera();
	~Camera();
	void Update(const Player& player);

	const VECTOR& GetPos() const { return m_pos; }

private:
	VECTOR m_pos;
};
