#include "Tetromino.h"
#include "Vector2.h"
#include <vector>
#include <iostream>
#include <numbers>


Tetromino::Tetromino(char displayCharacter, int tetrominoMatrix[4][4] = new int[4][4] { {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}})
{
	std::string s(1, displayCharacter);
	this->displayCharacter = s;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			this->tetrominoMatrix[i][j] = tetrominoMatrix[i][j];
		}
	}

};

void Tetromino::Rotate(int amount) // 1 -> 90 degree rotation clockwise, -1 -> 90 degree rotation anticlockwise, etc.
{
	int rotatedTetrominoMatrix[4][4]; // A buffer to store the rotated pixels of the tetromino
	
}

void Tetromino::Print()
{
	// Print all values.
	// Note that every character is padded with a space, as CMD uses halfwidth characters
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			std::cout << ((Tetromino::tetrominoMatrix[i][j] == 1) ? displayCharacter : " ") << " "; // Use the display character to 
		}
		std::cout << std::endl;
	}

}
Vector2 Tetromino::RotatePointAround(Vector2 originalPoint, Vector2 pointOfRotation, double degrees)
{
	// Convert cartesian coordinates to polar coordinates
	double deltaX = originalPoint.x - pointOfRotation.x;
	double deltaY = originalPoint.y - pointOfRotation.y;

	double theta = std::atan2(deltaY, deltaX);
	double radius = std::sqrt(std::pow(deltaX, 2) + std::pow(deltaY, 2));

	std::cout << "Theta: " << theta * 180/(atan(1)*4) << "\nRadius: " << radius;

	// Convert degrees input to radians and add it to the theta
	degrees *= 180 / (atan(1) * 4);
	theta += degrees;

	// Convert back to cartesian coordinates
	double rotatedX = radius * std::cos(theta);
	double rotatedY = radius * std::sin(theta);

	double finalXPosition = originalPoint.x + rotatedX;
	double finalYPosition = originalPoint.y + rotatedY;

	return Vector2(finalXPosition, finalYPosition);

};