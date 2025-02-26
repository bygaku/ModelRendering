#pragma once

/// @brief 定義
class Player;

/// @brief カメラ
class Camera
{
public:
	Camera();
	~Camera() = default;
	void Update(const Player& player);

	const VECTOR& GetPos() const { return m_pos; }

private:
	VECTOR m_pos;					/// @brief カメラ座標
	VECTOR m_lookPos;				/// @brief カメラ注視点

private:
	const float kNear	 =   5.0f;	/// @brief 最少表示距離
	const float kFar	 = 500.0f;	/// @brief 最大表示距離

	const float kPosVecY =   5.0f;	/// @brief カメラ座標のY位置
	const float kPosVecZ =  10.0f;	/// @brief プレイヤー座標からカメラ座標を引いたZ位置
};
