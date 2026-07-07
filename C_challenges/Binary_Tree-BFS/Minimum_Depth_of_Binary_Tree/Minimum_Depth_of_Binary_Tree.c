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


int minDepth(struct TreeNode* root)
{
    int currentlvl = 1;
    int front = 0;
    int rear = 0;
    if (!root)
        return -1;
    struct TreeNode* queue[SIZE];
    queue[rear++] = root;
    while (front < rear)
    {
        int levelSize = rear - front;
        for (int i = 0; i < levelSize; i++)
        {
            struct TreeNode* node = queue[front++];
            if (!node->left && !node->right)
                return currentlvl;
            if (node->left)
                queue[rear++] = node->left;
            if (node->right)
                queue[rear++] = node->right;
        }
        currentlvl++;
        
    }
    return currentlvl; 
}