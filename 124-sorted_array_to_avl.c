#include "binary_trees.h"

/**
 * create_tree - Recursively creates an AVL tree.
 * @node: A double pointer to the root node of the AVL tree to create.
 * @array: An array of integers.
 * @size: The size of the array.
 * @mode: 1 to add on the left, 2 to add on the right.
 *
 * Description: This function recursively creates an
 * AVL tree from a sorted array.
 * It splits the array into two halves and adds th
 * e middle element to the current node.
 * Then, it recursively creates the left and right subtrees.
 */
void create_tree(avl_t **node, int *array, size_t size, int mode)
{
	size_t middle;

	if (size == 0)
		return;

	/* Calculate the middle index of the current array segment */
	middle = (size / 2);
	middle = (size % 2 == 0) ? middle - 1 : middle;

	/* Add the middle element to the current node based on the mode */
	if (mode == 1)
	{
		(*node)->left = binary_tree_node(*node, array[middle]);
		create_tree(&((*node)->left), array, middle, 1);
		create_tree(&((*node)->left), array + middle + 1, (size - 1 - middle), 2);
	}
	else
	{
		(*node)->right = binary_tree_node(*node, array[middle]);
		create_tree(&((*node)->right), array, middle, 1);
		create_tree(&((*node)->right), array + middle + 1, (size - 1 - middle), 2);
	}
}

/**
 * sorted_array_to_avl - Creates the root node and calls create_tree.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: A pointer to the root node of the created AVL tree.
 *
 * Description: This function creates an AVL tree from a sorted
 * array by first creating the root node with the
 * middle element of the array, then recursively
 * adding the left and right subtrees.
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root;
	size_t middle;

	root = NULL;

	if (size == 0)
		return (NULL);

	/* Calculate the middle index of the array */
	middle = (size / 2);
	middle = (size % 2 == 0) ? middle - 1 : middle;

	/* Create the root node with the middle element of the array */
	root = binary_tree_node(root, array[middle]);

	/* Recursively create the left and right subtrees */
	create_tree(&root, array, middle, 1);
	create_tree(&root, array + middle + 1, (size - 1 - middle), 2);

	return (root);
}

