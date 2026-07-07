#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool PathSum(struct TreeNode* root, int targetSum, int sum)
{
    if (!root)
        return false;
    sum += root->val;
    if ((!root->right && !root->left) && targetSum == sum)
        return true;
    return PathSum(root->left, targetSum, sum) && PathSum(root->right, targetSum, sum);
}

bool hasPathSum(struct TreeNode* root, int targetSum)
{
    if (!root)
        return false;
    int sum = 0;
    return (PathSum(root, targetSum, sum));
}