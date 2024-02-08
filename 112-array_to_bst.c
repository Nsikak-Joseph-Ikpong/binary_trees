#include "binary_trees.h"

/**
 * array_to_bst - Builds a binary search tree from an array.
 * @array: A pointer to the first element of the array to be converted.
 * @size: The number of elements in @array.
 *
 * Return: A pointer to the root node of the created BST, or NULL upon failure.
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *tree = NULL;
	size_t i, j;

	/* Check if the array pointer is not NULL */
	if (array == NULL)
		return (NULL);

	/* Loop through the array elements */
	for (i = 0; i < size; i++)
	{
		/* Check if the current element already exists in the tree */
		for (j = 0; j < i; j++)
		{
			if (array[j] == array[i])
				break;
		}
		/* If the current element does not exist in the tree, insert it */
		if (j == i)
		{
			/* Insert the current element into the BST */
			if (bst_insert(&tree, array[i]) == NULL)
				return (NULL); /* Return NULL upon failure */
		}
	}

	return (tree); /* Return the root node of the created BST */
}

