

int max(int a, int b)
{
    return (a > b ? a : b);
}

int longestOnes(int* nums, int numsSize, int k) {
    int start = 0;
    int zeros = 0;
    int best = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] == 0)
            zeros++;
        while (zeros > k)
        {
            if (nums[start] == 0)
                zeros--;
            start++;
        }
        int sizeW = i - start + 1;
        best = max(best, sizeW);
    }
    return best;
}

#include <stdio.h>
int main()
{
    int arr[11] = {1,1,1,0,0,0,1,1,1,1,0};
    printf("%d\n", longestOnes(arr, 11, 2));
}