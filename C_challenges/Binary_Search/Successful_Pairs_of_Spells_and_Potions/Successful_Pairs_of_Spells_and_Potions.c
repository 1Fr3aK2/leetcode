#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b)
{
    int x = *(const int *)a;
    int y = *(const int *)b;

    if (x == y)
        return 0;
    return (x > y ? 1 : -1); 
}


int* successfulPairs(int* spells, int spellsSize, int* potions, int potionsSize, long long success, int* returnSize)
{
    int *res = (int *)malloc(spellsSize * sizeof(int));
    qsort(potions, potionsSize, sizeof(int), compare);
    int count = 0;
    int mid;
    int first;
    for (int i = 0; i < spellsSize; i++)
    {
        int low = 0;
        int high = potionsSize - 1;
        first = potionsSize;
        while (low <= high)
        {
            mid = low + (high - low) /2;
            if (spells[i] * (long long)potions[mid] >= success)
            {
                first = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        res[i] = potionsSize - first;
    }
    *returnSize = spellsSize;
    return res;
}


int main()
{
    int arr[3] = {3,1,2};
    int portions[5] = {8, 5, 8};
    int success = 16;
    int returnsize;
    int *res = successfulPairs(arr, 3, portions, 5, success, &returnsize);
    printf("Array:\n");
    for (int i = 0; i < 3; i++)
        printf("%d\n", res[i]);
}