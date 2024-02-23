#pragma once
#include <Windows.h>
#include <vector>
#include <iostream>

class ButtonDownHandler
{
	// L, U, D, R, HardDrop, 90Clock, 90AntiClock, 180, HoldPiece
	// "https://learn.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes?redirectedfrom=MSDN"
	//																			 F     D     S     A
	std::vector<int> arrowKeyCodes{ VK_LEFT, VK_UP, VK_DOWN, VK_RIGHT, VK_SPACE, 0x46, 0x44, 0x53, 0x41};
	std::vector<bool> arrowKeysPressed{ false, false, false, false, false, false, false, false, };
	std::vector<bool> arrowKeysAcknowledged{ false, false, false, false, false, false, false, false, };
	std::vector<bool> arrowKeysDown{ false, false, false, false, false, false, false, false, };

	std::string ConvertBoolVectorToString(std::vector<bool> boolList);

public:

	ButtonDownHandler();

	void Update();
	void Print();

	virtual void LeftKeyPressed();
	virtual void DownKeyPressed();
	virtual void UpKeyPressed();
	virtual void RightKeyPressed();

	virtual void RotateLeftKeyPressed();
	virtual void RotateRightKeyPressed();
	virtual void Rotate180KeyPressed();
	virtual void HoldPieceKeyPressed();
};

