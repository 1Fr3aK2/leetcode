#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

struct				TreeNode
{
	int				val;
	struct TreeNode	*left;
	struct TreeNode	*right;
};

#define SIZE 10000

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced,
	assume caller calls free().
 */

void	dfs(struct TreeNode *root, int targetSum, int sum, int *path,
		int pathSize, int **result, int *returnSize, int *returnColumnSizes)
{
	if (!root)
		return ;
	// Atualiza a soma e adiciona o nó ao caminho
	sum += root->val;
	path[pathSize++] = root->val;
	// Se chegou a uma folha
	if (!root->left && !root->right)
	{
		if (sum == targetSum)
		{
			// Copia o caminho encontrado
			result[*returnSize] = (int *)malloc(sizeof(int) * pathSize);
			for (int i = 0; i < pathSize; i++)
				result[*returnSize][i] = path[i];
			returnColumnSizes[*returnSize] = pathSize;
			(*returnSize)++;
		}
		return ;
	}
	dfs(root->left, targetSum, sum, path, pathSize, result, returnSize,
		returnColumnSizes);
	dfs(root->right, targetSum, sum, path, pathSize, result, returnSize,
		returnColumnSizes);
}

int	**pathSum(struct TreeNode *root, int targetSum, int *returnSize,
		int **returnColumnSizes)
{
	*returnSize = 0;

	int **result = (int **)malloc(sizeof(int *) * SIZE);
	*returnColumnSizes = (int *)malloc(sizeof(int) * SIZE);

	int path[SIZE];

	dfs(root, targetSum, 0, path, 0, result, returnSize, *returnColumnSizes);

	return (result);
}