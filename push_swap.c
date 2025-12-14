#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stacks *stacks;

	if (argc < 2)
		return (0);
	stacks = malloc(sizeof(t_stacks));
	if (stacks == NULL)
		return (1);
	stacks_in_null(stacks);
	in_sort_number(stacks, argc, argv);
	index_stack(stacks);
	execute_sort(stacks);
	free_stack_a(&stacks->A);
	free_stack_b(&stacks->B);
	free(stacks);
	return (0);
}