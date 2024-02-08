#include "binary_trees.h"

/**
 * binary_tree_sibling - Finds the sibling of a
 *                       node in a binary tree.
 * @node: A pointer to the node to find the sibling of.
 *
 * Return: If node is NULL or there is no sibling - NULL.
 *         Otherwise - a pointer to the sibling.
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);
       /* Return NULL if node is NULL or has no parent */
	if (node->parent->left == node)
		return (node->parent->right);
       /* Return the right child if node is the left child of its parent */
	return (node->parent->left);
       /* Return the left child if node is the right child of its parent */
}

