#include "binary_trees.h"

/**
 * array_to_avl - Builds an AVL tree from an array.
 * @array: A pointer to the first element of the array to be converted.
 * @size: The number of elements in @array.
 *
 * Return: A pointer to the root node of the created AVL, or NULL upon failure.
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;
	size_t i, j;

	/* If the array is NULL, return NULL */
	if (array == NULL)
		return (NULL);

	/* Iterate through the array and insert unique elements into the AVL tree */
	for (i = 0; i < size; i++)
	{
		/* Check if the current element is already inserted */
		for (j = 0; j < i; j++)
		{
			if (array[j] == array[i])
				break;
		}
		/* If the current element is unique, insert it into the AVL tree */
		if (j == i)
		{
			if (avl_insert(&tree, array[i]) == NULL)
				return (NULL);
		}
	}

	/* Return the root of the created AVL tree */
	return (tree);
}

