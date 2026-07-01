#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int equalPairs(int** grid, int gridSize, int* gridColSize)
{
    int count = 0;
    for (int i = 0; i < gridSize; i++)
    {
        for (int j = 0; j < gridSize; j++)
        {
            bool equal = true;
            for (int k = 0; k < gridSize; k++)
            {
                if (grid[i][k] != grid[k][j])
                {
                    equal = false;
                    break;
                }
            }
            if (equal)
                count++;
        }
    }
    return count;
}

int main()
{
    int row0[] = {3,2,1};
    int row1[] = {1,7,6};
    int row2[] = {2,7,7};

    int* grid[] = {row0, row1, row2};
    int colSize = 3;

    equalPairs(grid, 3, &colSize);

    return 0;
}