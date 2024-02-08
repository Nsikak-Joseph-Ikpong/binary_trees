#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Right-rotates a binary tree.
 * @tree: A pointer to the root node of the tree to rotate.
 *
 * Return: A pointer to the new root node after rotation.
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *pivot, *tmp;

	/* If tree or its left child is NULL, no rotation is possible */
	if (tree == NULL || tree->left == NULL)
		return (NULL);

	/* Store the left child of the tree as the pivot */
	pivot = tree->left;
	/* Set the right child of the pivot to the tree's left child */
	tmp = pivot->right;
	pivot->right = tree;
	tree->left = tmp;
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

