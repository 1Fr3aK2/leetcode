#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEFT 0
#define RIGHT 1

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int maxLength = 0;

int max(int a, int b)
{
    return (a > b ? a : b);
}

void dfs(struct TreeNode *root, int direction, int length)
{
    if (root == NULL)
        return;

    maxLength = max(maxLength, length);

    if (direction == LEFT)
    {
        dfs(root->left, RIGHT, length + 1); // continua o ZigZag
        dfs(root->right, LEFT, 1);          // começa outro ZigZag
    }
    else
    {
        dfs(root->right, LEFT, length + 1); // continua o ZigZag
        dfs(root->left, RIGHT, 1);          // começa outro ZigZag
    }
}

int longestZigZag(struct TreeNode *root)
{
    if (root == NULL)
        return 0;

    maxLength = 0;

    dfs(root->left, RIGHT, 1);
    dfs(root->right, LEFT, 1);

    return maxLength;
}