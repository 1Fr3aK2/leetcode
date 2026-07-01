#include <stdbool.h>
#include <limits.h>

bool increasingTriplet(int* nums, int numsSize) {
    int first = INT_MAX;
    int second = INT_MAX;
    for (int i = 0; i < numsSize; i++)
    {
        int x = nums[i];
        if (x <= first)
            first = x;
        else if (x <= second)
            second = x;
        else 
            return true;
    }
    return false;
}
