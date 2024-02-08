#include "binary_trees.h"

/**
 * bst_search - Searches for a value in a binary search tree.
 * @tree: A pointer to the root node of the BST to search.
 * @value: The value to search for in the BST.
 *
 * Return: If the tree is NULL or the value is not found, NULL.
 *         Otherwise, a pointer to the node containing the value.
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	/* Check if the tree is not NULL */
	if (tree != NULL)
	{
		/* If the current node contains the value, return the node */
		if (tree->n == value)
			return ((bst_t *)tree);
		/* If the value is less than the current node's value, search left */
		if (tree->n > value)
			return (bst_search(tree->left, value));
		/* If the value is greater than the current node's value, search right */
		return (bst_search(tree->right, value));
	}
	/* Return NULL if the tree is NULL or the value is not found */
	return (NULL);
}
