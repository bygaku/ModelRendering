#pragma once

/// @brief ��`
class Player;

/// @brief �J����
class Camera
{
public:
	Camera();
	~Camera() = default;
	void Update(const Player& player);

	const VECTOR& GetPos() const { return m_pos; }

private:
	VECTOR m_pos;					/// @brief �J�������W
	VECTOR m_lookPos;				/// @brief �J���������_

private:
	const float kNear	 =   5.0f;	/// @brief �ŏ��\������
	const float kFar	 = 500.0f;	/// @brief �ő�\������

	const float kPosVecY =   5.0f;	/// @brief �J�������W��Y�ʒu
	const float kPosVecZ =  10.0f;	/// @brief �v���C���[���W����J�������W��������Z�ʒu
};
