#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>



struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#define SIZE 10000

int** levelOrderBottom(struct TreeNode* root, int* returnSize, int** returnColumnSizes)
{
    *returnSize = 0;
    if (!root)
        return NULL;
    int **result = (int **)malloc(sizeof(int *) * SIZE);
    if (!result)
        return NULL;  
    *returnColumnSizes = (int *)malloc(sizeof(int) * SIZE);
    if (!*returnColumnSizes)
        return NULL;
    struct TreeNode* queue[SIZE];
    int front = 0;
    int rear = 0;
    queue[rear++] = root;
    while(front < rear)
    {
        int levelSize = rear - front;
        int *level = (int *)malloc(sizeof(int) * levelSize);
        for (int i = 0; i < levelSize; i++)
        {
            struct TreeNode* node = queue[front++];
            level[i] = node->val;
            if (node->left) 
                queue[rear++] = node->left;
            if (node->right) 
                queue[rear++] = node->right;
        }
        result[*returnSize] = level;
        (*returnColumnSizes)[*returnSize] = levelSize;
        (*returnSize)++;
    }
    int start = 0;
    int end = *returnSize - 1;
    while(start < end)
    {
        int *temp = result[start];
        result[start] = result[end];
        result[end] = temp;
        int temp1 = (*returnColumnSizes)[start];
        (*returnColumnSizes)[start] = (*returnColumnSizes)[end];
        (*returnColumnSizes)[end] = temp1;
        start++;
        end--;
    }
    return result;
}