//-----------------------------------------------------------------------------
// @brief  �v���C���[����.
// @remark -2025 Fujii Gaku-
//-----------------------------------------------------------------------------
#include "DxLib.h"
#include "Player.h"

// �ÓI�萔
// ���x�i1=1m�A60fps�Œ�Ƃ��āA����10km�j
// 10000m �� ���� �� �� �� �b �� �t���[��
const float Player::Speed = static_cast<float>(10000.0 / 60.0 / 60.0 / 60.0);
const float Player::Scale = 0.01f;			/// @brief �X�P�[��

Player::Player()
	: m_modelHandle(-1)
{
	m_modelHandle = MV1LoadModel("data/models/Slime.mv1");

	m_pos		  = VGet(0.0f, 0.5f, 0);
	m_velocity	  = VGet(0, 0, 0);
	m_dir		  = VGet(0, 0, 0);
	m_rota		  = VGet(0, DX_PI_F	/ -2.0f, 0);
}

Player::~Player()
{
	MV1DeleteModel(m_modelHandle);
}

void Player::Update()
{
	int Key = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	m_dir = VGet(0, 0, 0);
	if (Key & PAD_INPUT_UP)
	{
		m_dir = VAdd(m_dir, VGet(0, 1, 0));
	}
	
	if (Key & PAD_INPUT_DOWN)
	{
		m_dir = VAdd(m_dir, VGet(0, -1, 0));
	}

	if (Key & PAD_INPUT_RIGHT)
	{
		m_dir = VAdd(m_dir, VGet(1, 0, 0));
	}
	
	if (Key & PAD_INPUT_LEFT)
	{
		m_dir = VAdd(m_dir, VGet(-1, 0, 0));
	}

	if (VSquareSize(m_dir) > 0)
	{
		m_dir = VNorm(m_dir);
	}

	// �|�W�V�������X�V
	m_velocity = VScale(m_dir, Speed);
	m_pos	   = VAdd  (m_pos, m_velocity);

	// �͂������I������x���V�e�B�̕����Ƀf�B���N�V�����𒲐�
	if (VSize(m_velocity) != 0)
	{
		m_dir = VNorm(m_velocity);
	}

	MV1SetScale		 (m_modelHandle, VGet(Scale, Scale, Scale));
	MV1SetRotationXYZ(m_modelHandle, VGet(m_rota.x, m_rota.y, m_rota.z));
	MV1SetPosition	 (m_modelHandle, m_pos);
}

void Player::Draw()
{
	MV1DrawModel(m_modelHandle);
}
