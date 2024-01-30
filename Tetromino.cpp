#include "Tetromino.h"
#include "Vector2.h"
#include <vector>
#include <iostream>
#include <string>

Tetromino::Tetromino()
{

}

Tetromino::Tetromino(int ansiEscapeColor) : ansiEscapeColor{ ansiEscapeColor }
{

}

Tetromino::Tetromino(int ansiEscapeColor, int tetrominoMatrix[4][4] = new int[4][4] {0}) : ansiEscapeColor{ansiEscapeColor}{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			this->tetrominoMatrix[i][j] = tetrominoMatrix[i][j];
		}
	}
};

void Tetromino::Rotate(double degrees) // 1 -> 90 degree rotation clockwise, -1 -> 90 degree rotation anticlockwise, etc.
{
	// A buffer to store the rotated pixels of the tetromino
	int rotatedTetrominoMatrix[4][4] = { 0 };

	// Iterate through all indexes in the original tetromino matrix checking for 1s.
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			// Is the current pixel a 1?
			int currentPixel = Tetromino::tetrominoMatrix[i][j];
			if (currentPixel == 1)
			{
				//std::cout << "Moving " << i << ", " << j << " around " << Tetromino::centerOfRotation.x << ", " << Tetromino::centerOfRotation.y << " to ";
				Vector2 vectorAfterRotation = Tetromino::RotatePointAround(Tetromino::centerOfRotation, Vector2(i, j), degrees);

				int xPositionAfterRotation = std::round(vectorAfterRotation.x);
				int yPositionAfterRotation = std::round(vectorAfterRotation.y);

				//std::cout << xPositionAfterRotation << ", " << yPositionAfterRotation << std::endl;

				rotatedTetrominoMatrix[xPositionAfterRotation][yPositionAfterRotation] = 1;

			}
			// Otherwise do nothing
		}
	}



	// Set rotated matrix to tetrominoMatrix
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			Tetromino::tetrominoMatrix[i][j] = rotatedTetrominoMatrix[i][j];
		}
	}
}

void Tetromino::Print()
{
	// Print all values.
	// Note that every character is two characters long, as CMD seems to use halfwidth characters
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			std::string currentPixelTextToDisplay;
			if (Tetromino::tetrominoMatrix[i][j] == 1)
			{
				currentPixelTextToDisplay = "\033[" + std::to_string(Tetromino::ansiEscapeColor) + "m  \033[40m";
			}
			else
			{
				currentPixelTextToDisplay = "  ";
			}
			std::cout << currentPixelTextToDisplay; // Use the display character to 
		}
		std::cout << std::endl;
	}

}
Vector2 Tetromino::RotatePointAround(Vector2 pointOfRotation, Vector2 originalPoint, double degrees)
{
	// Convert cartesian coordinates to polar coordinates
	double deltaX = pointOfRotation.x - originalPoint.x;
	double deltaY = pointOfRotation.y - originalPoint.y;

	double theta = std::atan2(deltaY, deltaX);
	double radius = std::sqrt(std::pow(deltaX, 2) + std::pow(deltaY, 2));

	// Convert from degrees input to radians and add it to the theta
	degrees *= (atan(1) * 4) / 180;
	theta -= degrees;

	// Convert back to cartesian coordinates
	double rotatedX = radius * -std::cos(theta);
	double rotatedY = radius * -std::sin(theta);

	double finalXPosition = pointOfRotation.x + rotatedX;
	double finalYPosition = pointOfRotation.y + rotatedY;

	Vector2 finalPoint = Vector2(finalXPosition, finalYPosition);
	return finalPoint;

};