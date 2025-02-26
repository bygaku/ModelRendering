//-----------------------------------------------------------------------------
// @brief  カメラ実装.
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
	// カメラの位置を取得
	// 上下の動きにカメラの位置を合わせない
	m_pos = VGet(player.GetPos().x + 6.0f, 
				 kPosVecY, 
				 player.GetPos().z - kPosVecZ);

	// 注視点を取得
	m_lookPos = VGet(m_pos.x, m_pos.y - 1.0f, 0.0f);

	// カメラの位置を設定
	SetCameraPositionAndTarget_UpVecY(m_pos, m_lookPos);
}