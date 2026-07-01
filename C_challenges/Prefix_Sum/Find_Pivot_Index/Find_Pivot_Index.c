int pivotIndex(int* nums, int numsSize)
{
    int totalsum = 0;
    for (int i = 0; i < numsSize; i++)
        totalsum += nums[i];
    int lsum = 0;
    int rsum = 0;
    for (int i = 0; i < numsSize; i++)
    {
        rsum = totalsum - lsum - nums[i];
        if (lsum == rsum)
            return (i);
        lsum += nums[i];
    }
    return -1;
}
#include <stdio.h>
int main()
{
    int arr[6] = {1,7,3,6,5,6};
    printf("%d\n", pivotIndex(arr, 6));
}