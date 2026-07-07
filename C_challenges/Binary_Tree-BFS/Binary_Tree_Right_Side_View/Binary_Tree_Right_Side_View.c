#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void bfs(struct TreeNode* root, int depth, int *arr, int *i)
{
    if (!root)
        return;
    if (*i == depth)
        arr[(*i)++] = root->val;
    bfs(root->right, depth + 1, arr, i);
    bfs(root->left, depth + 1, arr, i);
}

int* rightSideView(struct TreeNode* root, int* returnSize)
{
    int *arr = (int *)malloc(sizeof(int) * SIZE);
    int i = 0;
    if (!arr)
        return NULL;
    bfs(root, 0, arr, &i);
    *returnSize = i;
    return (arr); 
}