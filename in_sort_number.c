#include "push_swap.h"

void	in_sort_number(t_stacks *stacks, int argc, char **argv)
{
	char	**split_number;
	int		i;
	int		j;
	t_node	*n1;
	int		value;

	i = 1;
	while (i < argc)
	{
		split_number = ft_split_ps(stacks, argv[i], ' ');
		j = 0;
		while (split_number[j] != NULL)
		{
			value = ft_atoi_check_ps(stacks, split_number[j],split_number);
			check_dup(stacks, value, split_number);
			n1 = node_new(value);
			if (n1 == NULL)
				free_split_stacks(stacks, split_number);
			under_add(&stacks->A, n1);
			j++;
		}
		free_sp(split_number);
		i++;
	}
}