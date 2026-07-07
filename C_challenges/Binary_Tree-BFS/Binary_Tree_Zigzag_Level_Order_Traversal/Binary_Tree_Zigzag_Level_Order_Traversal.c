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

int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes)
{
    *returnSize = 0;
    if (!root)
        return NULL;
    int **res = (int **)malloc(sizeof(int *) * SIZE);
    if (!res || !*res)
        return NULL;
    *returnColumnSizes = (int *)malloc(sizeof(int) * SIZE);
    if (!returnColumnSizes || !*returnColumnSizes)
        return NULL;
    int front = 0;
    int rear = 0;
    struct TreeNode* queue[SIZE];
    queue[rear++] = root;
    int leftright = 1;
    while(front < rear)
    {
        int levelSize = rear - front;
        int *level = (int *)malloc(sizeof(int) * SIZE);
        if (!level)
            return NULL;
        for (int i = 0; i < levelSize; i++)
        {
            struct TreeNode* node = queue[front++];
            if (leftright)
                level[i] = node->val;
            else
                level[levelSize - 1 - i] = node->val;
            if (node->left)
                queue[rear++] = node->left;
            if (node->right)
                queue[rear++] = node->right;
        }
        res[(*returnSize)] = level;
        (*returnColumnSizes)[*returnSize] = levelSize;
        (*returnSize)++;
        leftright = !leftright;
    }
    return res;
}