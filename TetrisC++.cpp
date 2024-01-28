#include <iostream>
#include "Tetromino.h"
#include <stdlib.h>
#include <chrono>
#include <thread>
#include <Windows.h>

int main()
{

    int exampleTetrominoMatrixI[4][4] = {
        {0, 0, 0, 0},
        {1, 1, 1, 1},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };
    Tetromino I{ 106, exampleTetrominoMatrixI};
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

}