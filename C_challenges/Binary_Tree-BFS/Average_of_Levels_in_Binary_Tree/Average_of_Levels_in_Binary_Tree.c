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
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define SIZE 10000

double* averageOfLevels(struct TreeNode* root, int* returnSize)
{
    *returnSize = 0;
    double *res = (double *)malloc(sizeof(double) * SIZE);
    if (!res)
        return NULL;
    int front = 0;
    int rear = 0;
    double division = 0;
    if (!root)
        return NULL;
    struct TreeNode* queue[SIZE];
    queue[rear++] = root;
    double sum = 0;
    while (front < rear)
    {
        int levelSize = rear - front;
        sum = 0;
        for (int i = 0; i < levelSize; i++)
        {
            struct TreeNode* node = queue[front++];
            sum += node->val;
            if (node->left)
                queue[rear++] = node->left;
            if (node->right)
                queue[rear++] = node->right;
        }
        division = sum / (levelSize);
        res[(*returnSize)++] = division; 
    }
    return res;
}