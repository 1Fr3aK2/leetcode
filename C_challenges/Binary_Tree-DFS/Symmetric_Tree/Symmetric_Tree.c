#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool mirror(struct TreeNode* left, struct TreeNode* right)
{
    if (!left && !right)
        return true;
    if (!left || !right)
        return false;
    if (left->val != right->val)
        return false;
    return mirror(left->left, right->right) && mirror(left->right, right->left);
}

bool isSymmetric(struct TreeNode* root)
{
    if (!root)
        return true;
    return mirror(root->left, root->right);
}