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

#define SIZE 10000

int leafs[SIZE];
int leafs1[SIZE];

void getLeaves(struct TreeNode* root, int *arr, int *index)
{
    if (root == NULL)
        return ;
    if (root->left == NULL && root->right == NULL)
    {
        arr[(*index)++] = root->val;
        return ;
    }
    getLeaves(root->left, arr, index);
    getLeaves(root->right, arr, index);
}

bool leafSimilar(struct TreeNode* root1, struct TreeNode* root2)
{
    memset(leafs, 0, sizeof(leafs));
    memset(leafs1, 0, sizeof(leafs));
    int i = 0;
    int j = 0;
    getLeaves(root1, leafs, &i);
    getLeaves(root2, leafs1, &j);
    if (i != j)
        return false;
    for (int k = 0; k < i; k++)
    {
        if (leafs[k] != leafs1[k])
            return false;
    }
    return true;
}