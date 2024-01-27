#include <iostream>
#include "Tetromino.h"

int main()
{
    int exampleTetrominoMatrix[4][4] = {
        {0, 1, 1, 0},
        {1, 1, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };

    Tetromino t{ '?', exampleTetrominoMatrix};


    t.Print();
    Vector2 res = t.RotatePointAround(Vector2(3, 5), Vector2(1, 4), 1);
    std::cout << res.x << " " << res.y;

}