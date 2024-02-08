#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree.
 * @tree: A double pointer to the root node of the BST to insert the value.
 * @value: The value to store in the node to be inserted.
 *
 * Return: A pointer to the created node, or NULL on failure.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *curr, *new;

	/* Check if the tree pointer is not NULL */
	if (tree != NULL)
	{
		curr = *tree;

		/* If the current node is NULL, create a new node with the given value */
		if (curr == NULL)
		{
			new = binary_tree_node(curr, value);
			if (new == NULL)
				return (NULL);
			return (*tree = new); /* Update the root and return the new node */
		}

		/* If the value is less than the current node's value, insert in the left subtree */
		if (value < curr->n)
		{
			if (curr->left != NULL) /* If the left child exists, recursively insert in the left subtree */
				return (bst_insert(&curr->left, value));

			/* If the left child does not exist, create a new node and assign it as the left child */
			new = binary_tree_node(curr, value);
			if (new == NULL)
				return (NULL);
			return (curr->left = new); /* Update the left child and return the new node */
		}

		/* If the value is greater than the current node's value, insert in the right subtree */
		if (value > curr->n)
		{
			if (curr->right != NULL) /* If the right child exists, recursively insert in the right subtree */
				return (bst_insert(&curr->right, value));

			/* If the right child does not exist, create a new node and assign it as the right child */
			new = binary_tree_node(curr, value);
			if (new == NULL)
				return (NULL);
			return (curr->right = new); /* Update the right child and return the new node */
		}
	}
	return (NULL); /* Return NULL if tree is NULL or value already exists in the tree */
}

