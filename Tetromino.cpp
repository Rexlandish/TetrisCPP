#include "Tetromino.h"
#include "Vector2.h"
#include <vector>
#include <iostream>


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

void Tetromino::Rotate(double degrees) // 1 -> 90 degree rotation clockwise, -1 -> 90 degree rotation anticlockwise, etc.
{
	// A buffer to store the rotated pixels of the tetromino
	int rotatedTetrominoMatrix[4][4] = { { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 } };

	// Iterate through all indexes in the original tetromino matrix checking for 1s.
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			// Is the current pixel a 1?
			int currentPixel = Tetromino::tetrominoMatrix[i][j];
			if (currentPixel == 1)
			{
				std::cout << "Moving " << i << ", " << j << " around " << Tetromino::centerOfRotation.x << ", " << Tetromino::centerOfRotation.y << " to ";
				Vector2 vectorAfterRotation = Tetromino::RotatePointAround(Tetromino::centerOfRotation, Vector2(i, j), degrees);

				int xPositionAfterRotation = std::round(vectorAfterRotation.x);
				int yPositionAfterRotation = std::round(vectorAfterRotation.y);

				std::cout << xPositionAfterRotation << ", " << yPositionAfterRotation << std::endl;

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



	// Overwrite tetromino in class with new tetromino

	// Rotate them given the degrees parameter and put them into rotatedTetrominoMatrix.
	// Move the buffer into the class's tetromino matrix.
	
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
Vector2 Tetromino::RotatePointAround(Vector2 pointOfRotation, Vector2 originalPoint, double degrees)
{
	// Convert cartesian coordinates to polar coordinates
	double deltaX = pointOfRotation.x - originalPoint.x;
	double deltaY = pointOfRotation.y - originalPoint.y;

	double theta = std::atan2(deltaY, deltaX);
	double radius = std::sqrt(std::pow(deltaX, 2) + std::pow(deltaY, 2));

	//std::cout << "Theta: " << theta * 180/(atan(1)*4) << "\nRadius: " << radius << std::endl;

	// Convert from degrees input to radians and add it to the theta
	degrees *= (atan(1) * 4) / 180;
	//std::cout << degrees << std::endl;
	theta -= degrees;

	//std::cout << theta << std::endl;

	// Convert back to cartesian coordinates
	double rotatedX = radius * -std::cos(theta);
	double rotatedY = radius * -std::sin(theta);

	double finalXPosition = pointOfRotation.x + rotatedX;
	double finalYPosition = pointOfRotation.y + rotatedY;

	Vector2 finalPoint = Vector2(finalXPosition, finalYPosition);
	return finalPoint;

};