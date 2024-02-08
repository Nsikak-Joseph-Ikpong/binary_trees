#include "binary_trees.h"

/**
 * binary_tree_node - Creates a binary tree node.
 * @parent: A pointer to the parent of the node to create.
 * @value: The value to put in the new node.
 *
 * Return: If an error occurs - NULL.
 *         Otherwise - a pointer to the new node.
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	/* Allocate memory for the new node */
	binary_tree_t *new;

	/* Check if memory allocation was successful */
	new = malloc(sizeof(binary_tree_t));
	if (new == NULL)
		return (NULL);

	/* Initialize the new node with the given value and parent */
	new->n = value;
	new->parent = parent;
	new->left = NULL;
	new->right = NULL;

	/* Return a pointer to the new node */
	return (new);
}

