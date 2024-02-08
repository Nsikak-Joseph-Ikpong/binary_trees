#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes.
 * @first: Pointer to the first node.
 * @second: Pointer to the second node.
 *
 * Return: If no common ancestors return NULL, else return common ancestor.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	/* Declare variables */
	binary_tree_t *mom, *pop;

	/* Check if either node is NULL */
	if (!first || !second)
		return (NULL);

	/* If the nodes are the same, return either node */
	if (first == second)
		return ((binary_tree_t *)first);

	/* Traverse up the tree to find common ancestor */
	mom = first->parent, pop = second->parent;
	if (first == pop || !mom || (!mom->parent && pop))
		return (binary_trees_ancestor(first, pop));
	else if (mom == second || !pop || (!pop->parent && mom))
		return (binary_trees_ancestor(mom, second));

	/* Return the common ancestor */
	return (binary_trees_ancestor(mom, pop));
}

