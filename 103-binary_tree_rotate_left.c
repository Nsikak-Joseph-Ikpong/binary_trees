#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Left-rotates a binary tree.
 * @tree: A pointer to the root node of the tree to rotate.
 *
 * Return: A pointer to the new root node after rotation.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *pivot, *tmp;

	/* If tree or its right child is NULL, no rotation is possible */
	if (tree == NULL || tree->right == NULL)
		return (NULL);

	/* Store the right child of the tree as the pivot */
	pivot = tree->right;
	/* Set the left child of the pivot to the tree's right child */
	tmp = pivot->left;
	pivot->left = tree;
	tree->right = tmp;
	/* Update the parent pointers */
	if (tmp != NULL)
		tmp->parent = tree;
	tmp = tree->parent;
	tree->parent = pivot;
	pivot->parent = tmp;
	if (tmp != NULL)
	{
		/* Update the parent's child pointer */
		if (tmp->left == tree)
			tmp->left = pivot;
		else
			tmp->right = pivot;
	}

	return (pivot);
}
