#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>


struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

#define SIZE 10000

bool isCompleteTree(struct TreeNode* root)
{
    if (!root)
        return false;
    int front = 0;
    int rear = 0;
    struct TreeNode* queue[SIZE];
    bool null = false;
    queue[rear++] = root;
    while (front < rear)
    {
        int levelSize = rear - front;
        for (int i = 0; i < levelSize; i++)
        {
            struct TreeNode* node = queue[front++];
            if (!node)
                null = true;
            else
            {
                if (null)
                    return false;
                queue[rear++] = node->left;
                queue[rear++] = node->right;
            }
        }
        
    }
    return true;
    
}