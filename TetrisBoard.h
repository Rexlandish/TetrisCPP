#include "Vector2.h"
#include "Tetromino.h"

class TetrisBoard
{

	int board[20][10] = { 0 };
	int activeTetrominoMatrix[4][4] = { 0 };
	int boardToDisplay[20][10] = { 0 };
public:

	Tetromino activeTetromino;
	Vector2 activeTetrominoPosition{ 0, 0 }; // Make this private

	TetrisBoard();
	void DrawTetrominoOnGrid();
	void DrawGrid();
	void DoRandomGridColours();
	void ResetBoardToDisplay();
};

