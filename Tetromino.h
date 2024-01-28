#include "Vector2.h"
#include <vector>
#include <iostream>

class Tetromino
{
public:

	Tetromino(char displayCharacter, int tetrominoMatrix[4][4]);

	int tetrominoMatrix[4][4]{ {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0 } };
	Vector2 centerOfRotation{ 1.5, 1.5 }; // array[1.5][1.5] represents the theoretical 'middle' position of the 4x4 array
	std::string displayCharacter{ "#" }; // What character to use when displaying this tetromino to the console

	void Rotate(double degrees); // 1 -> 90 degree rotation clockwise, -1 -> 90 degree rotation anticlockwise, etc.
	void Print();
	Vector2 RotatePointAround(Vector2 pointOfRotation, Vector2 originalPoint, double degrees);
};