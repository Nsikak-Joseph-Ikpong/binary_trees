#include "binary_trees.h"

size_t depth(const binary_tree_t *tree);

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
	size_t first_depth, second_depth;

	/* Check if either node is NULL */
	if (first == NULL || second == NULL)
		return (NULL);

	/* If the nodes are the same, return either node */
	if (first == second)
		return ((binary_tree_t *)first);

	/* If they share the same parent, return the parent */
	if (first->parent == second->parent)
		return ((binary_tree_t *)first->parent);

	/* If one is the parent of the other, return the parent */
	if (first == second->parent)
		return ((binary_tree_t *)first);

	/* If one is the parent of the other, return the parent */
	if (first->parent == second)
		return ((binary_tree_t *)second);

	/* Traverse up the tree to find common ancestor */
	for (first_depth = depth(first); first_depth > 1; first_depth--)
		first = first->parent;
	for (second_depth = depth(second); second_depth > 1; second_depth--)
		second = second->parent;

	/* If they end up at the same node, return that node */
	if (first == second)
		return ((binary_tree_t *)first);

	/* If they share the same parent, return the parent */
	if (first->parent == second->parent)
		return ((binary_tree_t *)first->parent);

	/* If one is the parent of the other, return the parent */
	if (first == second->parent)
		return ((binary_tree_t *)first);

	/* If one is the parent of the other, return the parent */
	if (first->parent == second)
		return ((binary_tree_t *)second);

	/* If no common ancestor is found, return NULL */
	return (NULL);
}

/**
 * depth - Measures the depth of a node in a binary tree.
 * @tree: A pointer to the node to measure the depth.
 *
 * Return: If tree is NULL, your function must return 0, else return the depth.
 */
size_t depth(const binary_tree_t *tree)
{
	/* If the parent is NULL, return 0 */
	return ((tree->parent != NULL) ? 1 + depth(tree->parent) : 0);
}

