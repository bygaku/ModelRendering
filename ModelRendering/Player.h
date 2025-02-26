#pragma once
#include "DxLib.h"


class Player 
{
public:
	Player();
	~Player();

	void Update();
	void Draw();

	// ���f���n���h���̎擾.
	int GetModelHandle() const { return m_modelHandle; }

	const VECTOR& GetPos() const { return m_pos; }
	const VECTOR& GetDir() const { return m_dir; }

private:
	int		m_modelHandle;		/// @brief ���f���n���h��
	VECTOR	m_pos;				/// @brief �|�W�V����
	VECTOR	m_velocity;			/// @brief �ړ���
	VECTOR	m_dir;				/// @brief ��]����
	VECTOR  m_rota;
	static const float Speed;	/// @brief ���x
	static const float Scale;	/// @brief �X�P�[��
};
