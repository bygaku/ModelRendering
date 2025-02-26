//-----------------------------------------------------------------------------
// @brief  �J��������.
// @remark -2025 Fujii Gaku-
//-----------------------------------------------------------------------------
#include "DxLib.h"
#include "Player.h"
#include "Camera.h"

Camera::Camera()
{
	m_pos	  = VGet(0, 0, 0);
	m_lookPos = VGet(0, 0, 0);

	SetCameraNearFar(kNear, kFar);
}

void Camera::Update(const Player& player)
{
	// �J�����̈ʒu���擾
	// �㉺�̓����ɃJ�����̈ʒu�����킹�Ȃ�
	m_pos = VGet(player.GetPos().x + 6.0f, 
				 kPosVecY, 
				 player.GetPos().z - kPosVecZ);

	// �����_���擾
	m_lookPos = VGet(m_pos.x, m_pos.y - 1.0f, 0.0f);

	// �J�����̈ʒu��ݒ�
	SetCameraPositionAndTarget_UpVecY(m_pos, m_lookPos);
}