struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int dfs(struct TreeNode* node, long long prev, int val)
{
    int counter = 0;
    if (!node)
        return 0;
    prev += node->val;
    if (prev == val)
        counter++;
    counter += dfs(node->left, prev, val);
    counter += dfs(node->right, prev, val);
    return counter;
}


int pathSum(struct TreeNode* root, int targetSum) 
{
    if (!root)
        return 0;
    return (dfs(root, 0, targetSum))  + pathSum(root->left, targetSum)
         + pathSum(root->right, targetSum);
}