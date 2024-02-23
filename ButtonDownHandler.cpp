#include "ButtonDownHandler.h"
#include <vector>
#include <Windows.h>
#include <sstream>

ButtonDownHandler::ButtonDownHandler()
{

}

void ButtonDownHandler::Update()
{

	//! REFACTOR THIS!!!!!!
	
	// See if any of the specified buttons are being held down.
	// update the key down array. 
	// On the next frame, then update they key acknowledged array

	// For each key
	for (int i = 0; i < arrowKeyCodes.size() - 1; i++)
	{
		// Update the currently-pressed-key array
		arrowKeysPressed[i] = GetKeyState(arrowKeyCodes[i]) & 0b10000000;// && 0x8000;

		
		// Update the acknowledged and/or button down array depending.
		// If the button is being pressed and...
		if (arrowKeysPressed[i])
		{

			if (arrowKeysDown[i])
			{
				arrowKeysDown[i] = false;
				arrowKeysAcknowledged[i] = true;
			}

			// ...the press hasn't been acknowledged yet...
			if (!arrowKeysAcknowledged[i])
			{
				// ...it is a button down event!
				arrowKeysDown[i] = true;
				// EVENT HERE
			}

		}
		else // Otherwise, if the button is not being pressed...
		{
			// ...set the other variables to false.
			arrowKeysDown[i] = false;
			arrowKeysAcknowledged[i] = false;
		}
		
	}
	
	/*				P	A	D
		...			_	_	_
		Key Press	#	_	#
		...			#	#	_
		Key Release	_	_	_		
	*/

}

// Nice representation of key presses
void ButtonDownHandler::Print()
{
	std::string arrowKeysPressedString = "Pressed:  " + ConvertBoolVectorToString(arrowKeysPressed);
	std::string arrowKeysAcknowledgedString = "Acknwlg.: " + ConvertBoolVectorToString(arrowKeysAcknowledged);
	std::string arrowKeysDownString = "Down:     " + ConvertBoolVectorToString(arrowKeysDown);


	std::stringstream finalOutputStringStream{};
	finalOutputStringStream << arrowKeysPressedString << "\n" << arrowKeysAcknowledgedString << "\n" << arrowKeysDownString;
	//finalOutputStringStream << arrowKeysPressedString << "\n" << arrowKeysDownString;
	
	std::cout << finalOutputStringStream.str();

}

void ButtonDownHandler::LeftKeyPressed() {}
void ButtonDownHandler::DownKeyPressed() {}
void ButtonDownHandler::UpKeyPressed() {}
void ButtonDownHandler::RightKeyPressed() {}

void ButtonDownHandler::RotateLeftKeyPressed() {}
void ButtonDownHandler::RotateRightKeyPressed() {}
void ButtonDownHandler::Rotate180KeyPressed() {}
void ButtonDownHandler::HoldPieceKeyPressed() {}

std::string ButtonDownHandler::ConvertBoolVectorToString(std::vector<bool> boolList)
{
	std::string stringToReturn{ "" };
	for (bool currentBool : boolList)
	{
		std::string symbolToAdd = currentBool ? "#" : "_";
		stringToReturn.append(symbolToAdd);
	}

	return stringToReturn;
}


