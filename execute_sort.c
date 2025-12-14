#include "push_swap.h"

unsigned int value_to_unsigned(int value)
{
	return ((unsigned int)value ^ 0x80000000u);
}

int	max_bit_size(t_stacks *stacks)
{
	unsigned int		max_key;
	unsigned int 		key;
	t_node	*n1;
	int		bit_size;

	max_key = value_to_unsigned(stacks->A.top->value);
	n1 = stacks->A.top;
	while (n1 != NULL)
	{
		key = value_to_unsigned(n1->value);
		if (max_key < key)
			max_key = key;
		n1 = n1->next;
	}
	bit_size = 0;
	while (max_key != 0)
	{
		max_key >>= 1;
		bit_size++;
	}
	return (bit_size);
}

void	radix_sort(t_stacks *stacks)
{
	int	i;
	int	size;
	int	bit_size;
	int	max_bit;
	unsigned int key;

	bit_size = 0;
	max_bit = max_bit_size(stacks);
	while (bit_size < max_bit)
	{
		i = 0;
		size = stacks->A.size;
		while (i < size)
		{
			key = value_to_unsigned(stacks->A.top->value);
			if (((key >> bit_size) & 1u) == 0u)
				pb_ps(stacks);
			else
				ra_ps(stacks);
			i++;
		}
		while (stacks->B.size != 0)
			pa_ps(stacks);
		bit_size++;
	}
}

void	execute_sort(t_stacks *stacks)
{
	if (ascending_order_check(&stacks->A))
		return ;
	else if (stacks->A.size == 2)
		sa_ps(stacks);
	else if (stacks->A.size == 3)
		sort_3(stacks);
	else if (stacks->A.size == 4)
		sort_4(stacks);
	else if (stacks->A.size == 5)
		sort_5(stacks);
	else
		radix_sort(stacks);
}
