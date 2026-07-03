#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>


int minEatingSpeed(int* piles, int pilesSize, int h)
{
    int low = 1; //defines the lower value possible
    int high = piles[0]; //defines default value
    int mid;
    for (int i = 1; i < pilesSize; i++)
    {
        if (piles[i] > high)
            high = piles[i];
        //finds the highest value in the arr in order to know which is the max number that can be returned
    }
    while (low < high)
    {
        int mid = low + (high - low) / 2; //chooses the mid value in (high - value) range
        int hours = 0; //number of spent hours eating
        for (int i = 0; i < pilesSize; i++)
            hours += ((piles[i] + mid - 1) /mid);   
        if (hours > h) //if it spends +time eating than expected
            low = mid + 1; //the range is lower by incrementing the minimum value
        else
            high = mid; //we store the the last possible value
    }
    return low;
}