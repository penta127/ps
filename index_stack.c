#include "push_swap.h"

void index_sort(int *index, int a_size)
{
	int i;
	int j;
	int sort_index;

	i = 0;
	while (i < a_size)
	{
		j = i + 1;
		while (j < a_size)
		{
			if (index[i] > index[j])
			{
				sort_index = index[i];
				index[i] = index[j];
				index[j] = sort_index;
			}
			j++;
		}
		i++;
	}
}

int index_search(int *index, int a_size, int value)
{
	int i;

	i = 0;
	while (i < a_size)
	{
		if (index[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

void index_stack(t_stacks *stacks)
{
	t_node *n1;
	int a_size;
	int *index;
	int i;

	a_size = stacks->A.size;
	n1 = stacks->A.top;
	index = malloc(sizeof(int) * a_size);
	if (!index)
		free_split_stacks(stacks, NULL);
	i = 0;
	while (n1)
	{
		index[i] = n1->value;
		n1 = n1->next;
		i++;
	}
	index_sort(index, a_size);
	n1 = stacks->A.top;
	while (n1)
	{
		n1->value = index_search(index, a_size, n1->value);;
		n1 = n1->next;
	}
	free(index);
}
