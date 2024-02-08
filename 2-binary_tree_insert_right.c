#include "binary_trees.h"

/**
 * binary_tree_insert_right - Insert a node as the right-child
 *                            of another in a binary tree.
 * @parent: A pointer to the node to insert the right-child in.
 * @value: The value to store in the new node.
 *
 * Return: If parent is NULL or an error occurs - NULL.
 *         Otherwise - a pointer to the new node.
 *
 * Description: If parent already has a right-child, the new node
 *              takes its place and the old right-child is set as
 *              the right-child of the new node.
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	if (parent == NULL)
		return (NULL);
       /* Return NULL if parent is NULL */

	new = binary_tree_node(parent, value);
       /* Create a new node */
	if (new == NULL)
		return (NULL);
       /* Return NULL if memory allocation fails */

	if (parent->right != NULL)
	       /* If parent already has a right-child */
	{
		new->right = parent->right;
	       /* Set new node's right child as parent's right child */
		parent->right->parent = new;
	       /* Update the old right-child's parent pointer */
	}
	parent->right = new;
       /* Set parent's right-child pointer to the new node */

	return (new);
       /* Return a pointer to the new node */
}

