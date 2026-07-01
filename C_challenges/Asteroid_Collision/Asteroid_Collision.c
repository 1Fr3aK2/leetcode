#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int* asteroidCollision(int* asteroids, int asteroidsSize, int* returnSize)
{
    int *res = (int *)malloc(sizeof(int) * asteroidsSize);
    int j = -1;
    for (int i = 0; i < asteroidsSize; i++)
    {
        int x = asteroids[i];
        bool alive = true;
        while (j >= 0 && alive && x < 0 && res[j] > 0)
        {
            if (res[j] < -x)
                j--;
            else if (res[j] == -x)
            {
                j--;
                alive = false;
            }
            else
                alive = false;
        }
        if (alive)
            res[++j] = x;
    }
    *returnSize = j + 1;
    return res;
}

int main()
{
    int ast[6] = {3,5,-6,2,-1,4};
    int ast1[3] = {5, 10, -5};
    int returnsize = 0;
    int *res = asteroidCollision(ast, 6, &returnsize);    
    for (int i = 0; i < 3; i++)
    {
        printf("%d\n", res[i]);
    }
}