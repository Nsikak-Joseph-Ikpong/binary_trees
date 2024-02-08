#include "binary_trees.h"
#include "limits.h"

/**
 * is_bst_helper - Checks if a binary tree is a valid binary search tree.
 * @tree: A pointer to the root node of the tree to check.
 * @lo: The value of the smallest node visited thus far.
 * @hi: The value of the largest node visited this far.
 *
 * Return: If the tree is a valid BST, 1, otherwise, 0.
 */
int is_bst_helper(const binary_tree_t *tree, int lo, int hi)
{
	/* If tree is not NULL */
	if (tree != NULL)
	{
		/* Check if the current node's value is within the valid range */
		if (tree->n < lo || tree->n > hi)
			return (0); /* Not a valid BST */

		/* Recursively check the left subtree with updated bounds */
		/* All nodes in the left subtree must be less than current node */
		if (!is_bst_helper(tree->left, lo, tree->n - 1))
			return (0);

		/* Recursively check the right subtree with updated bounds */
		/* All nodes in the right subtree must be greater than current node */
		if (!is_bst_helper(tree->right, tree->n + 1, hi))
			return (0);

		/* If both subtrees are valid BSTs, return 1 */
		return (1);
	}
	/* If tree is NULL, it is a valid BST */
	return (1);
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid binary search tree.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	/* If tree is NULL, it is not a valid BST */
	if (tree == NULL)
		return (0);
	/* Call the function with initial range set to range of integers */
	return (is_bst_helper(tree, INT_MIN, INT_MAX));
}

