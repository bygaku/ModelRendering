#pragma once

/// @brief ’è‹`
class Player;

/// @brief ƒJƒƒ‰
class Camera
{
public:
	Camera();
	~Camera() = default;
	void Update(const Player& player);

	const VECTOR& GetPos() const { return m_pos; }

private:
	VECTOR m_pos;
};
