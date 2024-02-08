#include "binary_trees.h"

/**
 * tree_size - Measures the sum of heights of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: The sum of heights of the tree, or 0 if tree is NULL.
 */
size_t tree_size(const binary_tree_t *tree)
{
	size_t height_l = 0; /* Height of the left subtree */
	size_t height_r = 0; /* Height of the right subtree */

	if (!tree)
		return (0);

	if (tree->left)
		height_l = 1 + tree_size(tree->left);
       /* Recursively calculate the height of the left subtree */

	if (tree->right)
		height_r = 1 + tree_size(tree->right);
       /* Recursively calculate the height of the right subtree */

	return (height_l + height_r);
       /* Return the sum of heights of left and right subtrees */
}

/**
 * heap_to_sorted_array - Converts a Binary Max
 * Heap to a sorted array of integers.
 * @heap: Pointer to the root node of the heap to convert.
 * @size: Address to store the size of the array.
 *
 * Return: Pointer to array sorted in descending order.
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int i; /* Loop variable */
	int *a = NULL; /* Pointer to the array */

	if (!heap || !size)
		return (NULL);

	*size = tree_size(heap) + 1;
       /* Calculate the size of the array */

	a = malloc(sizeof(int) * (*size));
       /* Allocate memory for the array */

	if (!a)
		return (NULL);

	for (i = 0; heap; i++)
		a[i] = heap_extract(&heap);
       /* Extract elements from the heap into the array */

	return (a); /* Return the sorted array */
}

