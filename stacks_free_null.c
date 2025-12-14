#include "push_swap.h"

void	stacks_in_null(t_stacks *stacks)
{
	stacks->A.top = NULL;
	stacks->A.under = NULL;
	stacks->A.size = 0;
	stacks->B.top = NULL;
	stacks->B.under = NULL;
	stacks->B.size = 0;
}

void free_stack_a(t_stack *a)
{
	t_node *n1;
	t_node *n1_next;

	n1 = a->top;
	while (n1 != NULL)
	{
		n1_next = n1->next;
		free(n1);
		n1 = n1_next;
	}
	a->top = NULL;
	a->under = NULL;
	a->size = 0;
}

void free_stack_b(t_stack *b)
{
	t_node *n1;
	t_node *n1_next;

	n1 = b->top;
	while (n1 != NULL)
	{
		n1_next = n1->next;
		free(n1);
		n1 = n1_next;
	}
	b->top = NULL;
	b->under = NULL;
	b->size = 0;
}

void	free_sp(char **out)
{
	size_t	i;

	i = 0;
	while (out[i] != NULL)
	{
		free(out[i]);
		i++;
	}
	free(out);
}

void free_split_stacks(t_stacks *stacks, char **split_number)
{
	if (split_number)
		free_sp(split_number);
	free_stack_a(&stacks->A);
	free_stack_b(&stacks->B);
	free(stacks);
	write(2, "Error\n", 6);
	exit(1);
}