//-----------------------------------------------------------------------------
// @brief  メイン処理.
// @remark -2025 Fujii Gaku-
//-----------------------------------------------------------------------------

/// @brief Applies to "Main func" or something else in this project.
#include "DxLib.h"
#include "Screen.h"
#include "LoopCondition.h"

#include "Player.h"
#include "Camera.h"

int WINAPI WinMain(_In_		HINSTANCE hInstance,
				   _In_opt_ HINSTANCE hPrevInstance,
				   _In_		LPSTR lpCmdLine,
				   _In_		int nCmdShow)
{
	if (DxLib_Init() == -1) { return -1; }

	SetGraphMode(kSCREEN_W, kSCREEN_H, 16);
	ChangeWindowMode(TRUE);

	SetDrawScreen	   (DX_SCREEN_BACK);
	SetUseZBufferFlag  (TRUE);
	SetWriteZBufferFlag(TRUE);
	SetUseBackCulling  (TRUE);

	Player* player = new Player();
	auto* camera = new Camera();
	while (isLoop())
	{
		player->Update();
		camera->Update(*player);

		player->Draw();
		

#ifdef _DEBUG
		// XYZ軸
		float lineSize = 300.0f;
		DrawLine3D(VGet(-lineSize, 0, 0), VGet(lineSize, 0, 0), GetColor(255, 0, 0));
		DrawLine3D(VGet(0, -lineSize, 0), VGet(0, lineSize, 0), GetColor(0, 255, 0));
		DrawLine3D(VGet(0, 0, -lineSize), VGet(0, 0, lineSize), GetColor(0, 0, 255));
#endif  // デバッグ描画

	}

	delete player;
	delete camera;

	DxLib_End();

	return 0;
}