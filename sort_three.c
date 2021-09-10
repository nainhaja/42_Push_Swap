#include "push_swap.h"

void	check_value(t_node *stack_a, int val)
{
	int	flag;

	flag = 0;
	while (stack_a != NULL)
	{
		if (stack_a->value == val)
		{
			flag = 1;
		}
		stack_a = stack_a->next;
	}
	if (flag == 1)
	{
		ft_putstr("Error\n");
		exit(0);
	}
}

void	check_duplicate(t_node *stack_a)
{
	int	size;
	int	i;

	i = 0;
	size = list_size(stack_a);
	while (i < size && stack_a->next != NULL)
	{
		check_value(stack_a->next, stack_a->value);
		stack_a = stack_a->next;
		i++;
	}
}

void	sort_three(t_node **stack_a)
{
	int		fr;
	int		sec;
	int		th;
	t_node	*start;

	start = *stack_a;
	fr = start->value;
	sec = start->next->value;
	th = start->next->next->value;
	if (fr > sec && fr < th && sec < th)
		swap_a(*stack_a);
	else if (fr > sec && fr > th && sec > th)
	{
		swap_a(*stack_a);
		rrotate_a(stack_a);
	}
	else if (fr > sec && fr > th && sec < th)
		rotate_a(start);
	else if (fr < sec && fr < th && sec > th)
	{
		swap_a(*stack_a);
		rotate_a(*stack_a);
	}
	else if (fr < sec && fr > th && sec > th)
		rrotate_a(stack_a);
}
