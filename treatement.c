#include "push_swap.h"

int	get_meduim(int argc, t_node *stack_a, int div)
{
	int	i;

	i = 0;
	while (stack_a != NULL)
	{
		if (i >= ((argc / div) - 1))
			return (stack_a->value);
		stack_a = stack_a->next;
		i++;
	}
	return (0);
}

int	get_indmid(t_node *stack_a, int mid)
{
	int	i;

	i = 0;
	while (stack_a != NULL)
	{
		if (mid >= stack_a->value)
			return (i);
		stack_a = stack_a->next;
		i++;
	}
	return (i);
}

int	get_indmid2(t_node *stack_a, int mid)
{
	int	i;
	int	cpt;

	i = 0;
	cpt = 0;
	while (stack_a != NULL)
	{
		if (mid >= stack_a->value)
			cpt = i;
		stack_a = stack_a->next;
		i++;
	}
	return (cpt);
}

int	search_max(t_node *stack_b)
{
	int	max;
	int	i;
	int	ind;

	max = -2147483648;
	i = 0;
	while (stack_b->next != NULL)
	{
		if (max < stack_b->value)
		{
			max = stack_b->value;
			ind = i;
		}
		stack_b = stack_b->next;
		i++;
	}
	if (max < stack_b->value)
	{
		max = stack_b->value;
		ind = i;
	}
	return (ind);
}

int	ft_prep(t_node *stack_a, int argc, int div)
{
	int		res;
	t_node	*stack_c;
	t_node	*tmp;

	stack_c = copyList(stack_a);
	quick_sort(stack_c);
	res = get_meduim(argc - 1, stack_c, div);
	tmp = stack_c;
	while (stack_c != NULL)
	{
		tmp = stack_c->next;
		free(stack_c);
		stack_c = tmp;
	}
	return (res);
}
