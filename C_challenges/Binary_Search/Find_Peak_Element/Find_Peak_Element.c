#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>



int findPeakElement(int* nums, int numsSize)
{
    int low = 0;
    int high = numsSize - 1;
    int mid;
    while (low < high)
    {
        mid = low + (high - low) / 2;
        if (nums[mid] > nums[mid + 1])
            high = mid;
        else
            low = mid + 1;
    }
    return low;
}
