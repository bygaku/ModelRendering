#pragma once

/// @brief ループ終了条件
/// @return TRUE：常にループする
inline bool isLoop()
{
	if (ProcessMessage())
		return false;

	if (ScreenFlip())
		return false;

	if (ClearDrawScreen())
		return false;

	if (CheckHitKey(KEY_INPUT_ESCAPE))
		return false;

	return true;
}
