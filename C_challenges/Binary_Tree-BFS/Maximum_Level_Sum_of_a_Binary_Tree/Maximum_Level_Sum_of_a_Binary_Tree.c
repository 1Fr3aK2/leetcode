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

int findMax(int a, int b)
{
    return (a > b ? a : b);
}


int maxLevelSum(struct TreeNode* root)
{
    if (!root)
        return -1;
    struct TreeNode* queue[SIZE];
    int front = 0;
    int rear = 0;
    int max = INT_MIN;
    int sum = 0;
    int currentlvl = 1;
    int ans = 1;
    queue[rear++] = root;
    while (front < rear)
    {
        sum = 0;
        int levelSize = rear - front;
        for (int i = 0; i < levelSize; i++)
        {
            struct TreeNode* node = queue[front++];
            sum += node->val;
            if (node->left)
                queue[rear++] = node->left;
            if (node->right)
                queue[rear++] = node->right;
        }
        if (sum > max)
        {
            max = findMax(sum, max);
            ans = currentlvl;
        }   
        currentlvl++;
    }
    return ans;
}