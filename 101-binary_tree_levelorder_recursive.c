#include "binary_trees.h"

/**
 * struct node_s - singly linked list
 * @node: const binary tree node
 * @next: points to the next node
 */
typedef struct node_s
{
	const binary_tree_t *node;
	struct node_s *next;
} ll;

/**
 * append - adds a new node at the end of a linked list
 * @head: pointer to head of linked list
 * @btnode: const binary tree node to append
 * Return: pointer to head, or NULL on failure
 */
ll *append(ll *head, const binary_tree_t *btnode)
{
	ll *new = NULL, *last = NULL;

	/* Allocate memory for the new node */
	new = malloc(sizeof(*new));
	if (new)
	{
		/* Initialize the new node */
		new->node = btnode;
		new->next = NULL;

		/* If the list is empty, new node is the head */
		if (!head)
			head = new;
		else
		{
			/* Find the last node in the list */
			last = head;
			while (last->next)
				last = last->next;

			/* Append the new node */
			last->next = new;
		}
	}
	return (head);
}

/**
 * free_list - frees all the nodes in a linked list
 * @head: pointer to the head of list_t linked list
 */
void free_list(ll *head)
{
	ll *ptr = NULL;

	/* Free each node in the list */
	while (head)
	{
		ptr = head->next;
		free(head);
		head = ptr;
	}
}

/**
 * get_children - appends children of parent to linked list
 * @head: Pointer to head of linked list where children will be appended
 * @parent: Pointer to node whose children we want to append
 * Return: Pointer to head of linked list of children
 */
ll *get_children(ll *head, const binary_tree_t *parent)
{
	/* Append left child if exists */
	if (parent->left)
		head = append(head, parent->left);

	/* Append right child if exists */
	if (parent->right)
		head = append(head, parent->right);

	return (head);
}

/**
 * levels_rec - Calls func on all nodes at each level
 * @head: Pointer to head of linked list with nodes at one level
 * @func: Pointer to a function to call for each node
 */
void levels_rec(ll *head, void (*func)(int))
{
	ll *children = NULL, *curr = NULL;

	/* If the list is empty, return */
	if (!head)
		return;

	/* Traverse the list and process each node */
	for (curr = head; curr != NULL; curr = curr->next)
	{
		func(curr->node->n);
		children = get_children(children, curr->node);
	}

	/* Recursively process the children nodes */
	levels_rec(children, func);
	free_list(children);
}

/**
 * binary_tree_levelorder - Goes through a binary tree
 *                          using level-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	ll *children = NULL;

	/* Call function for root node */
	func(tree->n);

	/* Get children of root node */
	children = get_children(children, tree);

	/* Recursively process children nodes */
	levels_rec(children, func);

	/* Free the list of children */
	free_list(children);
}

