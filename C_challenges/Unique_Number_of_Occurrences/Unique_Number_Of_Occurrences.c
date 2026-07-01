#include <stdbool.h>
#include <unistd.h>
#include <string.h>

#define SIZE 200001 
#define OFFSET 100000
int times[SIZE];
bool seen[SIZE];
bool uniqueOccurrences(int* arr, int arrSize)
{
    memset(times, 0, sizeof(times));
    memset(seen, 0, sizeof(seen));
    for (int i = 0; i < arrSize; i++)
    {
        int x = arr[i];
        times[x + OFFSET]++;
    }
    for (int i = 0; i < SIZE; i++)
    {
        if (times[i] == 0)
            continue;
        if (seen[times[i]])
            return false;
        seen[times[i]] = true;
    }
    return true;   
}

#include <stdio.h>
int main()
{
    int arr[6] = {1,2,2,1,1,3};
    if (!uniqueOccurrences(arr, 6))
        printf("FALSE\n");
    else
        printf("TRUE\n");
}