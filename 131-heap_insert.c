#include "binary_trees.h"

/**
 * heap_insert - Inserts a value in a Max Binary Heap.
 * @root: A double pointer to the root node of the Heap to insert the value.
 * @value: The value to store in the node to be inserted.
 *
 * Return: A pointer to the created node, NULL on failure.
 *
 * Description: This function inserts a value into a Max Binary Heap.
 * It first calculates the number of nodes and
 * the number of leaves in the tree to determine
 * the position of the new node. Then,
 * it traverses the tree to the first empty slot
 * based on the binary representation of the number of leaves.
 * After inserting the
 * new node, it performs a "bubble-up" operation to maintain the max heap property.
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *tree, *new, *flip;
	int size, leaves, sub, bit, level, tmp;

	/* Check if root is NULL */
	if (!root)
		return (NULL);
	/* If root is NULL, create a new node */
	if (!(*root))
		return (*root = binary_tree_node(NULL, value));

	/* Assign root to tree and calculate the number of nodes */
	tree = *root;
	size = binary_tree_size(tree);
	leaves = size;

	/* Calculate the level and the number of leaves */
	for (level = 0, sub = 1; leaves >= sub; sub *= 2, level++)
		leaves -= sub;

	/* Traverse to the first empty slot based on the
	 * binary representation of the number of leaves */
	for (bit = 1 << (level - 1); bit != 1; bit >>= 1)
		tree = leaves & bit ? tree->right : tree->left;

	/* Create a new node */
	new = binary_tree_node(tree, value);
	/* Insert the new node to the first empty slot */
	leaves & 1 ? (tree->right = new) : (tree->left = new);

	/* Bubble-up operation to maintain max heap property */
	flip = new;
	for (; flip->parent && (flip->n > flip->parent->n); flip = flip->parent)
	{
		tmp = flip->n;
		flip->n = flip->parent->n;
		flip->parent->n = tmp;
		new = new->parent;
	}

	return (new);
}

/**
 * binary_tree_size - Measures the size of a binary tree.
 * @tree: A pointer to the root node of the tree
 * to measure the size of.
 *
 * Return: The size of the tree, 0 if tree is NULL.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	/* If tree is NULL, return 0 */
	if (!tree)
		return (0);

	/* Calculate the size of the tree recursively */
	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}

