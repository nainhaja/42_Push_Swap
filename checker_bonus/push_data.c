#include "../push_swap.h"

void	insert_tostackk(int argc, char **argv, t_node **stack_a)
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

void	check_value(t_node *stack_a, int val)
{
	int	flag;

	flag = 0;
	while (stack_a != NULL)
	{
		if (stack_a->value == val)
			flag = 1;
		stack_a = stack_a->next;
	}
	if (flag == 1)
	{
		ft_putstr("Error\n");
		exit(0);
	}
}
