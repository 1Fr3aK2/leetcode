
int guess(int num);


#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int guessNumber(int n)
{
    int low = 1;
    int high = n;
    int res;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        res = guess(mid);
        if (res == 0)
            return mid;
        if (res == -1)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}


int main()
{
    int x = 90;
    printf("My number is: %d, result after guessNumber(): %d\n", x, guessNumber(x));
}