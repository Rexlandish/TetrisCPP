#pragma once
#include "Vector2.h"
#include <vector>
#include <iostream>

class Tetromino
{
public:

	Tetromino();
	Tetromino(int ansiEscapeColor);
	Tetromino(int ansiEscapeColor, int tetrominoMatrix[4][4]);

	int tetrominoMatrix[4][4]{ 0 };
	Vector2 centerOfRotation{ 1, 1 }; // array[1.5][1.5] represents the theoretical 'middle' position of the 4x4 array
	int ansiEscapeColor;

	void Rotate(double degrees); // 1 -> 90 degree rotation clockwise, -1 -> 90 degree rotation anticlockwise, etc.
	void Print();
	Vector2 RotatePointAround(Vector2 pointOfRotation, Vector2 originalPoint, double degrees);
};