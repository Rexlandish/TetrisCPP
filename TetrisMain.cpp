#include "TetrisMain.h"
#include "Tetromino.h"
#include "ButtonDownHandler.h"

// Initialization of pieces
int exampleTetrominoMatrixI[4][4] = {
    {0, 0, 0, 0},
    {1, 1, 1, 1},
    {0, 0, 0, 0},
    {0, 0, 0, 0}
};
Tetromino I{ 106, exampleTetrominoMatrixI };
I.centerOfRotation = Vector2(1.5, 1.5);

int exampleTetrominoMatrixJ[4][4] = {
    {1, 0, 0, 0},
    {1, 1, 1, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0}
};
Tetromino J{ 104, exampleTetrominoMatrixJ };

int exampleTetrominoMatrixL[4][4] = {
{0, 0, 1, 0},
{1, 1, 1, 0},
{0, 0, 0, 0},
{0, 0, 0, 0}
};
Tetromino L{ 43, exampleTetrominoMatrixL };

int exampleTetrominoMatrixO[4][4] = {
{0, 1, 1, 0},
{0, 1, 1, 0},
{0, 0, 0, 0},
{0, 0, 0, 0}
};
Tetromino O{ 103, exampleTetrominoMatrixO };
O.centerOfRotation = Vector2(0.5, 1.5);

int exampleTetrominoMatrixS[4][4] = {
{0, 1, 1, 0},
{1, 1, 0, 0},
{0, 0, 0, 0},
{0, 0, 0, 0}
};
Tetromino S{ 102, exampleTetrominoMatrixS };

int exampleTetrominoMatrixT[4][4] = {
    {0, 1, 0, 0},
    {1, 1, 0, 0},
    {0, 1, 0, 0},
    {0, 0, 0, 0}
};
Tetromino T{ 105, exampleTetrominoMatrixT };

int exampleTetrominoMatrixZ[4][4] = {
    {1, 1, 0, 0},
    {0, 1, 1, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0}
};
Tetromino Z{ 101, exampleTetrominoMatrixZ };

std::vector<Tetromino> tetrominos = { I, J, L, O, S, T, Z };

/*
// Display all pieces and rotations
Tetromino z1{ 101, exampleTetrominoMatrixZ };
Tetromino z2{ 101, exampleTetrominoMatrixZ };
Tetromino I1{ 106, exampleTetrominoMatrixI }; I1.centerOfRotation = Vector2(1.5, 1.5);
Tetromino I2{ 106, exampleTetrominoMatrixI }; I2.centerOfRotation = Vector2(1.5, 1.5);
Tetromino t1{ 105, exampleTetrominoMatrixT };
Tetromino t2{ 105, exampleTetrominoMatrixT };
while (true)
{
    std::cout << "Z piece rotating 90 degrees\n";
    z1.Print();
    std::cout << "Z piece rotating 45 degrees\n";
    z2.Print();

    std::cout << "I piece rotating 90 degrees\n";
    I1.Print();
    std::cout << "I piece \"rotating\" 50 degrees\n";
    I2.Print();

    std::cout << "T piece rotating 90 degrees\n";
    t1.Print();
    std::cout << "T piece rotating 45 degrees\n";
    t2.Print();

    z1.Rotate(90);
    z2.Rotate(45);

    I1.Rotate(90);
    I2.Rotate(50);

    t1.Rotate(90);
    t2.Rotate(45);
    Sleep(100);
    std::cout << std::flush;
    system("CLS");
}
*/

/*
while (true)
{
    system("CLS");

    for (Tetromino &tetromino : tetrominos)
    {
        tetromino.Print();
        tetromino.Rotate(90);
        std::cout << std::endl;
    }

    Sleep(100);
}
*/


/*
// Do a flashing random colour thing
while (true)
{
    system("CLS");
    TetrisBoard board;
    board.DoRandomGridColours();
    Sleep(100);
}
*/



/*
TetrisBoard tetrisBoard;
tetrisBoard.activeTetromino = Z;
while (true)
{

    tetrisBoard.activeTetrominoPosition = Vector2(rand() % 10, rand() % 10);
    for (int i = 0; i < 16; i++)
    {
        system("CLS");
        tetrisBoard.activeTetromino.Rotate(45);
        tetrisBoard.DrawTetrominoOnGrid();
        tetrisBoard.DrawGrid();
        Sleep(25);
    }
}
*/



ButtonDownHandler buttonDownHandler{};

while (true)
{
    buttonDownHandler.Update();
    buttonDownHandler.Print();
    Sleep(50);
    system("CLS");
}

