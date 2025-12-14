#include "push_swap.h"

void	pa_ps_helper(t_stack *a, t_node *n1)
{
	if (a->size == 0)
	{
		a->top = n1;
		a->under = n1;
		n1->before = NULL;
		n1->next = NULL;
	}
	else
	{
		n1->next = a->top;
		n1->before = NULL;
		a->top->before = n1;
		a->top = n1;
	}
}

void	pa_ps(t_stacks *stacks)
{
	t_node	*n1;

	if (stacks->B.size == 0)
		return ;
	n1 = stacks->B.top;
	stacks->B.top = n1->next;
	if (stacks->B.top != NULL)
		stacks->B.top->before = NULL;
	else
		stacks->B.under = NULL;
	pa_ps_helper(&stacks->A, n1);
	stacks->B.size--;
	stacks->A.size++;
	write(1, "pa\n", 3);
}
