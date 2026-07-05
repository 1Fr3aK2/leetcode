#include <unistd.h>
#include <stdlib.h>
#include <string.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int maxDepth(struct TreeNode* root)
{
    if (!root)
        return 0;
    int rd = maxDepth(root->right);
    int ld = maxDepth(root->left);
    return (1 + ((rd > ld) ? rd : ld));
}