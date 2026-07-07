#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int maxD(struct TreeNode* root)
{
    if (!root)
        return 0;
    int left = maxD(root->left) + 1;
    int right = maxD(root->right) + 1;
    return (left > right ?  left : right);
}

bool isBalanced(struct TreeNode* root)
{
    if (!root)
        return true;
    int left = maxD(root->left);
    int right = maxD(root->right);
    if (abs(left - right) > 1)
        return false;
    return (isBalanced(root->left) && isBalanced(root->right));
}