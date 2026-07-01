int max(int a, int b)
{
    return (a > b ? a : b);
}

int largestAltitude(int* gain, int gainSize)
{
    int curr = 0;
    int best = curr;
    for (int i = 0; i < gainSize; i++)
    {
        curr = curr + gain[i];
        best = max(curr, best);   
    }
    return best;
}

#include <stdio.h>
int main()
{
    int arr[5] = {-5,1,5,0,-7};
    printf("%d\n", largestAltitude(arr, 5));
}