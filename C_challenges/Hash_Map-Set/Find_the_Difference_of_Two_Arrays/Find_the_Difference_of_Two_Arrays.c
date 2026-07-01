/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define OFFSET 100000

bool seen1[200001];
bool seen2[200001];
bool added1[200001];
bool added2[200001];

int** findDifference(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize, int** returnColumnSizes)
{
    memset(seen1, 0, sizeof(seen1));
    memset(seen2, 0, sizeof(seen2));
    memset(added1, 0, sizeof(added1));
    memset(added2, 0, sizeof(added2));

    int **res = (int **)malloc(2 * sizeof(int *));
    int *ans0 = (int *)malloc(nums1Size * sizeof(int));
    int *ans1 = (int *)malloc(nums2Size * sizeof(int));
    int c0 = 0;
    int c1 = 0;
    for (int i = 0; i < nums1Size; i++)
        seen1[nums1[i] + OFFSET] = true;
    for (int i = 0; i < nums2Size; i++)
        seen2[nums2[i] + OFFSET] = true;
    for (int i = 0; i < nums1Size; i++)
    {
        int x = nums1[i];
        if (!seen2[x + OFFSET] && !added1[x + OFFSET])
        {
            ans0[c0++] = x;
            added1[x + OFFSET] = true;
        }
    }
    for (int i = 0; i < nums2Size; i++)
    {
        int x = nums2[i];
        if (!seen1[x + OFFSET] && !added2[x + OFFSET])
        {
            ans1[c1++] = x;
            added2[x + OFFSET] = true;
        }
    }
    res[0] = ans0;
    res[1] = ans1;
    *returnSize = 2;
    *returnColumnSizes = (int *)malloc(*returnSize * sizeof(int));
    (*returnColumnSizes)[0] = c0;
    (*returnColumnSizes)[1] = c1;
    return res;
}