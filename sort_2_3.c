#include "push_swap.h"

void sort_2(t_stacks *stacks)
{
	sa_ps(stacks);
}

void sort_3_helper(t_stacks *stacks, int max_position)
{
	if (max_position == 1)
	{
		ra_ps(stacks);
		if (ascending_order_check(&stacks->A) == false)
			sa_ps(stacks);
	}
	else if (max_position == 2)
	{
		sa_ps(stacks);
		ra_ps(stacks);
		if (ascending_order_check(&stacks->A) == false)
			sa_ps(stacks);
	}
	else if (max_position == 3)
		sa_ps(stacks);
}

void sort_3(t_stacks *stacks)
{
	t_node *n1;
	int max_value;
	int max_position;
	int i;

	i = 1;
	max_position = 1;
	max_value = stacks->A.top->value;
	n1 = stacks->A.top;
	while (n1)
	{
		if (max_value < n1->value)
		{
			max_value = n1->value;
			max_position = i;
		}
		n1 = n1->next;
		i++;
	}
	sort_3_helper(stacks, max_position);
}