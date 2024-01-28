#include <iostream>
#include "Tetromino.h"
#include <stdlib.h>
int main()
{

    int exampleTetrominoMatrixI[4][4] = {
        {0, 0, 0, 0},
        {1, 1, 1, 1},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };
    Tetromino I{ '#', exampleTetrominoMatrixI};
    I.centerOfRotation = Vector2(1.5, 1.5);

    int exampleTetrominoMatrixT[4][4] = {
        {0, 1, 0, 0},
        {1, 1, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 0, 0}
    };
    Tetromino T{ '#', exampleTetrominoMatrixT };
    T.centerOfRotation = Vector2(1, 1);
    
    while (true)
    {
        T.Print();
        L.Print();
        T.Rotate(90);
        L.Rotate(90);
        std::cin.ignore();
        system("CLS");
    }

}