#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int findMax(int a, int b)
{
    return (a > b ? a : b);
}


int getD(struct TreeNode* root, int *max)
{
    if (!root)
        return 0;
    int left = getD(root->left, max);
    int right = getD(root->right, max);
    *max = findMax(*max, left + right);
    return findMax(left, right) + 1;
}

int diameterOfBinaryTree(struct TreeNode* root)
{
    int max = INT_MIN;
    getD(root, &max);
    return max;
}