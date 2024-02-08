#include "binary_trees.h"
#include "102-binary_tree_is_complete.c"
/* Include the implementation of binary_tree_is_complete */

/**
 * check_max - Goes through a binary tree
 * checking if each node is greater than its children.
 * @tree: Pointer to the root node of the tree to check.
 * Return: 1 if all nodes are greater than their
 * children, 0 otherwise.
 *
 * Description: This function recursively traverses
 * the binary tree and checks if each node
 * is greater than its left and right children.
 * If any node violates this property, the function
 * returns 0, indicating that the tree is not a max heap.
 * If all nodes satisfy the property,
 * the function returns 1, indicating that the tree is a max heap.
 */
int check_max(const binary_tree_t *tree)
{
	int tmp1 = 1, tmp2 = 1;

	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (1);

	if (tree->left)
	{
		if (tree->n <= tree->left->n)
			return (0);
		tmp1 = check_max(tree->left);
	}

	if (tree->right)
	{
		if (tree->n <= tree->right->n)
			return (0);
		tmp2 = check_max(tree->right);
	}

	return (tmp1 && tmp2);
}

/**
 * binary_tree_is_heap - Checks if a binary tree is a max heap.
 * @tree: Pointer to the root node of the tree to check.
 * Return: 1 if the tree is a max heap, 0 otherwise.
 *
 * Description: This function checks if a binary
 * tree is a max heap. First, it checks if
 * the tree is complete using the binary_tree_is_complete
 * function. If the tree is complete,
 * it calls the check_max function to verify
 * if each node is greater than its children.
 * If both conditions are met, the function
 * returns 1, indicating that the tree is a max heap.
 * Otherwise, it returns 0.
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	int tmp;

	if (!tree)
		return (0);

	tmp = binary_tree_is_complete(tree);
	if (!tmp)
		return (0);

	return (check_max(tree));
}

