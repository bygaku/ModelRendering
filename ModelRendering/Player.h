#pragma once
#include "DxLib.h"


class Player 
{
public:
	Player();				// コンストラクタ
	~Player();				// デストラクタ

	void Update();			// 更新
	void Draw();			// 描画

	// モデルハンドルの取得.
	int GetModelHandle() const { return m_modelHandle; }

	const VECTOR& GetPos() const { return m_pos; }
	const VECTOR& GetDir() const { return m_dir; }

private:
	int		m_modelHandle;		/// @brief モデルハンドル
	VECTOR	m_pos;				/// @brief ポジション
	VECTOR	m_velocity;			/// @brief 移動力
	VECTOR	m_dir;				/// @brief 回転方向
	VECTOR  m_rota;
	static const float Speed;	/// @brief 速度
	static const float Scale;	/// @brief スケール
};
