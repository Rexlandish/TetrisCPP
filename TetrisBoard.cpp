#include "TetrisBoard.h"
//#include "Tetromino.h"
#include "Vector2.h"
#include <stdlib.h>
#include <iostream>


TetrisBoard::TetrisBoard()
{
	
}

void TetrisBoard::DrawTetrominoOnGrid()
{

	ResetBoardToDisplay();

	// * Draw tetromino on grid at the position stored by activeTetrominoPosition
	// Iterate through the active tetromino matrix, checking for ones.
	// If a one is found, offset it's x y position by activeTetrominoPosition and...
	// ...write the one in the new position in the temporary grid display buffer above.

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (activeTetromino.tetrominoMatrix[i][j] == 1)
			{
				int xPosition = i + activeTetrominoPosition.x;
				int yPosition = j + activeTetrominoPosition.y;
				boardToDisplay[xPosition][yPosition] = activeTetromino.ansiEscapeColor;
			}
		}
	}

}

void TetrisBoard::DrawGrid()
{
	// Iterate through the display grid, and add a border by outputting inbetween the two for statements.

	for (int i = 0; i < 20; i++)
	{
		std::cout << ".";

		for (int j = 0; j < 10; j++)
		{

			int currentPixelColor = (boardToDisplay[i][j] == 0 ? 40 : boardToDisplay[i][j]);

			std::cout << "\033[" << currentPixelColor << "m  \033[40m";

			//std::cout << board[i][j] << " ";
		}

		std::cout << "." << std::endl;
	}
	
	// All lower boundary
	for (int i = 0; i < (20 + 2)/2; i++)
	{
		std::cout << ". ";
	}
}

void TetrisBoard::DoRandomGridColours()
{
	// This function is just to assign a random symbol to each element in the index
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			int randomValue = rand() % 8;
			//std::cout << randomValue;
			board[i][j] = randomValue;
		}
	}

	DrawGrid();
}

void TetrisBoard::ResetBoardToDisplay()
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			boardToDisplay[i][j] = 0;
		}
	}
}