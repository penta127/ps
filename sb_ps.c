#include "push_swap.h"

void	sb_ps_size_two(t_stack *b)
{
	t_node	*n1;
	t_node	*n2;

	n1 = b->top;
	n2 = b->under;
	b->top = n2;
	b->under = n1;
	n1->next = NULL;
	n1->before = n2;
	n2->before = NULL;
	n2->next = n1;
}

void	sb_ps_size_over_two(t_stack *b)
{
	t_node	*n1;
	t_node	*n2;
	t_node	*n3;

	n1 = b->top;
	n2 = n1->next;
	n3 = n2->next;
	b->top = n2;
	n2->before = NULL;
	n2->next = n1;
	n1->before = n2;
	n1->next = n3;
	n3->before = n1;
}

void	sb_ps(t_stacks *stacks)
{
	if (stacks->B.size <= 1)
		return ;
	else if (stacks->B.size == 2)
	{
		sb_ps_size_two(&stacks->B);
	}
	else if (stacks->B.size >= 3)
	{
		sb_ps_size_over_two(&stacks->B);
	}
	write(1, "sb\n", 3);
}