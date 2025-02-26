//-----------------------------------------------------------------------------
// @brief  �J��������.
// @remark -2025 Fujii Gaku-
//-----------------------------------------------------------------------------
#include "DxLib.h"
#include "Player.h"
#include "Camera.h"

Camera::Camera()
{
	SetCameraNearFar(1.0f, 100.0f);

	m_pos = VGet(0, 0, 0);
}

void Camera::Update(const Player& player)
{
	// �J�����̈ʒu���擾
	// �㉺�̓����ɃJ�����̈ʒu�����킹�Ȃ�
	m_pos = VGet(player.GetPos().x + 6.0f, 
				 5.0f, 
				 player.GetPos().z - 10.0f);

	// �����_���擾
	VECTOR lookPos = VGet(m_pos.x, m_pos.y - 1.0f, 0.0f);

	// �J�����̈ʒu��ݒ�
	SetCameraPositionAndTarget_UpVecY(m_pos, lookPos);
}