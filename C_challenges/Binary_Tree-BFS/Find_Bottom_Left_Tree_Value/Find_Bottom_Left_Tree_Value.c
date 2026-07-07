#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

#define SIZE 10000

int findBottomLeftValue(struct TreeNode* root)
{
    if (!root)
        return 0;
    int front = 0;
    int rear = 0;
    struct TreeNode* queue[SIZE];
    queue[rear++] = root;
    int ans;
    while(front < rear)
    {
        int levelSize = rear - front;
        for (int i = 0; i < levelSize; i++)
        {
            struct TreeNode* node = queue[front++];
            if (i == 0)
                ans = node->val;
            if (node->left)
                queue[rear++] = node->left;
            if (node->right)
                queue[rear++] = node->right;
        }
    }
    return ans;
}