#include "push_swap.h"

void	pb_ps_helper(t_stack *b, t_node *n1)
{
	if (b->size == 0)
	{
		b->top = n1;
		b->under = n1;
		n1->before = NULL;
		n1->next = NULL;
	}
	else
	{
		n1->next = b->top;
		n1->before = NULL;
		b->top->before = n1;
		b->top = n1;
	}
}

void	pb_ps(t_stacks *stacks)
{
	t_node	*n1;

	if (stacks->A.size == 0)
		return ;
	n1 = stacks->A.top;
	stacks->A.top = n1->next;
	if (stacks->A.top != NULL)
		stacks->A.top->before = NULL;
	else
		stacks->A.under = NULL;
	pb_ps_helper(&stacks->B, n1);
	stacks->A.size--;
	stacks->B.size++;
	write(1, "pb\n", 3);
}
