#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

//iterative way


#define SIZE 10000

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


struct TreeNode* invertTree(struct TreeNode* root)
{
    if (!root)
        return NULL;
    struct TreeNode* stack[SIZE];
    int top = 0;
    stack[top++] = root;
    while (top > 0)
    {
        struct TreeNode* node = stack[top--];
        struct TreeNode* temp = node->left;
        node->left = node->right;
        node->right = temp;
        if (node->left)
            stack[top++] = node->left;
        if (node->right)
            stack[top++] = node->right;
    }
    return root;
}