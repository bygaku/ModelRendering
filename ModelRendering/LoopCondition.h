#pragma once

/// @brief ���[�v�I������
/// @return TRUE�F��Ƀ��[�v����
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
