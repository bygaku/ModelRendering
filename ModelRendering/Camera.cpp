//-----------------------------------------------------------------------------
// @brief  カメラ実装.
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
	// カメラの位置を取得
	// 上下の動きにカメラの位置を合わせない
	m_pos = VGet(player.GetPos().x + 6.0f, 
				 5.0f, 
				 player.GetPos().z - 10.0f);

	// 注視点を取得
	VECTOR lookPos = VGet(m_pos.x, m_pos.y - 1.0f, 0.0f);

	// カメラの位置を設定
	SetCameraPositionAndTarget_UpVecY(m_pos, lookPos);
}