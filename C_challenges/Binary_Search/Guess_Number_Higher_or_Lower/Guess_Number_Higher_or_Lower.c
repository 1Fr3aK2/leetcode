
 @param  num   your guess
 @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);


#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int guessNumber(int n){
	int mid = (n /2);
    int left = n - mid;
    int right = n - (mid + 1);
    int res = 0;
    while (res != n)
    {
        res = guess(mid);
        if (res == -1)
            res = guess(right);
        else if (res == 1)
            res = guess(left);
        else if (res == 0)
            return res;
    }
    return res;
}