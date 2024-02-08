#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the size of.
 *
 * Return: The size of the tree.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 0;

	/* If tree is not NULL, traverse the tree to calculate its size */
	if (tree)
	{
		/* Increment the size for the current node */
		size += 1;
		/* Recursively calculate the size of the left subtree */
		size += binary_tree_size(tree->left);
		/* Recursively calculate the size of the right subtree */
		size += binary_tree_size(tree->right);
	}
	return (size);
}

