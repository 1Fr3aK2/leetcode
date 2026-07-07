#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

#define SIZE 10000

int findMax(int a, int b)
{
    return (a > b ? a : b);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* largestValues(struct TreeNode* root, int* returnSize)
{
    *returnSize = 0;
    if (!root)
        return NULL;
    int *res = (int *)malloc(sizeof(int) * SIZE);
    if (!res)
        return NULL;
    int front = 0;
    int rear = 0;
    struct TreeNode* queue[SIZE];
    queue[rear++] = root;
    while (front < rear)
    {
        int max = INT_MIN;
        int levelSize = rear - front;
        for (int i = 0; i < levelSize; i++)
        {
            struct TreeNode* node = queue[front++];
            max = findMax(max, node->val);
            if (node->left)
                queue[rear++] = node->left;
            if (node->right)
                queue[rear++] = node->right;
        }
        res[(*returnSize)++] = max;
    }
    return res;
}