#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

#define SIZE 10000

int* rightSideView(struct TreeNode* root, int* returnSize)
{
    *returnSize = 0;

    // Allocate memory for the result array.
    int *arr = (int *)malloc(sizeof(int) * SIZE);
    if (!arr)
        return NULL;

    // If the tree is empty, return an empty result.
    if (!root)
        return NULL;

    // Queue used to perform the BFS traversal.
    struct TreeNode *queue[SIZE];
    int front = 0;
    int rear = 0;

    // Enqueue the root node.
    queue[rear++] = root;

    // Traverse the tree level by level.
    while (front < rear)
    {
        // Number of nodes in the current level.
        int levelSize = rear - front;

        // Process every node in the current level.
        for (int i = 0; i < levelSize; i++)
        {
            // Dequeue the next node.
            struct TreeNode *node = queue[front++];

            // The last processed node in the current level
            // is the node visible from the right side.
            if (i == levelSize - 1)
                arr[(*returnSize)++] = node->val;

            // Enqueue the children for the next level.
            if (node->left)
                queue[rear++] = node->left;

            if (node->right)
                queue[rear++] = node->right;
        }
    }

    return arr;
}