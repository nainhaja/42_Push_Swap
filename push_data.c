#include "push_swap.h"

void	return_a(t_node **stack_b, t_node **stack_a, int ind, int argc)
{
	int		i;
	t_node	*stack_c;

	stack_c = *stack_b;
	i = 0;
	if (ind <= argc / 2)
	{
		while (i < ind)
		{
			rotate_b(*stack_b);
			i++;
		}
		push_a(stack_b, stack_a);
	}
	else if (ind > (argc / 2))
	{
		i = argc / 2;
		while (ind < argc - 1)
		{
			rrotate_b(stack_b);
			ind++;
		}
		push_a(stack_b, stack_a);
	}
}

void	return_to_a(t_node **stack_b, int argc, t_node **stack_a)
{
	int		minus;
	t_node	*stack_c;

	minus = 0;
	stack_c = *stack_b;
	while (stack_c->next != NULL && argc - minus > 0)
	{
		return_a(&stack_c, stack_a, search_max(stack_c), argc - minus);
		minus++;
	}
	return_a(&stack_c, stack_a, search_max(stack_c), argc - minus);
}

void	get_data(t_node **stack_a, int mid, int argc, t_node **stack_b)
{
	int		get_ind1;
	int		get_ind2;
	t_node	*stack_c;

	stack_c = *stack_a;
	get_ind1 = get_indmid(stack_c, mid);
	get_ind2 = get_indmid2(stack_c, mid);
	if (get_ind1 < argc - get_ind2)
	{
		while (get_ind1 > 0)
		{
			rotate_a(*stack_a);
			get_ind1--;
		}
		push_b(stack_a, stack_b);
	}
	else
	{
		while (get_ind2 < argc)
		{
			rrotate_a(stack_a);
			get_ind2++;
		}
		push_b(stack_a, stack_b);
	}
}

void	push_rest(t_node **stack_a, t_node **stack_b)
{
	t_node	*stack_c;
	int		i;
	int		size;

	i = 0;
	stack_c = *stack_a;
	size = list_size(stack_c);
	if (list_size(stack_c) == 1)
		push_b(&stack_c, stack_b);
	else
	{
		while (i < size)
		{
			push_b(&stack_c, stack_b);
			i++;
		}
	}
}

void	insert_tostack(int argc, char **argv, t_node **stack_a)
{
	int		i;
	t_node	*node_toadd;
	int		cpt;

	cpt = argc - 2;
	i = argc - 1;
	node_toadd = NULL;
	while (i > 0)
	{
		node_toadd = create_new_node(ft_atoi(argv[i]));
		insert(stack_a, node_toadd);
		*stack_a = node_toadd;
		cpt--;
		i--;
	}
}
