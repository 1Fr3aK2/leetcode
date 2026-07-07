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

int getSum(struct TreeNode* root, int sum)
{
    if (!root)
        return 0;
    sum = sum * 10 + root->val;
    if (!root->left && !root->right)
        return sum;
    return getSum(root->left, sum) + getSum(root->right, sum);
}


int sumNumbers(struct TreeNode* root)
{
    int sum = 0;
    return getSum(root, sum);
}