#include "push_swap.h"

void	check_dup(t_stacks *stacks, int check_value, char **split_number)//node split free No
{
	t_node	*source;

	source = stacks->A.top;
	while (source != NULL)
	{
		if (check_value == source->value)
			free_split_stacks(stacks, split_number);
		source = source->next;
	}
}

t_node	*node_new(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (node == NULL)
		return (NULL);
	node->value = value;
	node->next = NULL;
	node->before = NULL;
	return (node);
}

void	under_add(t_stack *stack, t_node *node)
{
	if (stack->under == NULL)
	{
		stack->top = node;
		stack->under = node;
	}
	else
	{
		stack->under->next = node;
		node->before = stack->under;
		stack->under = node;
	}
	stack->size++;
}
