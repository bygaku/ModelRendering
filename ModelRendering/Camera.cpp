//-----------------------------------------------------------------------------
// @brief  カメラ実装.
// @remark -2025 Fujii Gaku-
//-----------------------------------------------------------------------------
#include "DxLib.h"
#include "Player.h"
#include "Camera.h"

Camera::Camera()
{
	//奥行0.1～1000までをカメラの描画範囲とする
	SetCameraNearFar(1.0f, 200.0f);

	m_pos = VGet(0, 0, 0);
}

Camera::~Camera()
{
	// default.
}

void Camera::Update(const Player& player)
{
	// 大きさ0.5のマップチップを、課題当初のStageData1ColNum個(16)配置する
	// プレイヤーの地面のY位置を0としたいので、地上部のマップチップの数は二つ減らした位置で調整
	// その真ん中に表示するので半分を計算で出す
	// プレイヤーのX座標には追従したいのでplayerのXを使う
	VECTOR playerPos = player.GetPos();
	VECTOR cameraPos = VGet(playerPos.x, 0.725f * (16 - 2) * 0.5f, playerPos.z - 10.0f);

	// 注視する視点は、カメラと平行にまっすぐz=0地点
	VECTOR lookPos = VGet(cameraPos.x, cameraPos.y, 0.0f);

	m_pos = cameraPos;

	// カメラに位置を反映.
	SetCameraPositionAndTarget_UpVecY(m_pos, lookPos);
}