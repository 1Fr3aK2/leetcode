#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int max(int a, int b)
{
    return (a > b ? a : b);
}

int goodNodes1(struct TreeNode* root, int val)
{
    int counter = 0;
    if (!root)
        return 0;
    if (root->val >= val)
        counter++;
    val = max(root->val, val);
    counter += goodNodes1(root->left, val);
    counter += goodNodes1(root->right, val);
    return counter;
}


int goodNodes(struct TreeNode* root)
{
    return (goodNodes1(root, root->val));
}