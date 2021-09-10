#include "push_swap.h"

int	list_size(t_node *stack_a)
{
	int	i;

	i = 0;
	while (stack_a != NULL)
	{
		i++;
		stack_a = stack_a->next;
	}
	return (i);
}

void	finish_five(t_node **stack_a, t_node **stack_b)
{
	push_b(stack_a, stack_b);
	sort_four(stack_a, stack_b);
	push_a(stack_b, stack_a);
}

void	last_case(t_node **stack_a, int flag, t_node **stack_b)
{
	if (flag == 0)
	{
		rrotate_a(stack_a);
		rrotate_a(stack_a);
		finish_five(stack_a, stack_b);
	}
	else if (flag == 1)
	{
		rrotate_a(stack_a);
		finish_five(stack_a, stack_b);
	}
}

int	*ft_remp(t_node *stack_a, int argc)
{
	int	*t;
	int	i;

	i = 0;
	t = malloc(sizeof(int) * argc);
	while (stack_a->next != NULL)
	{
		t[i] = stack_a->value;
		stack_a = stack_a->next;
		i++;
	}
	t[i] = stack_a->value;
	return (t);
}

void	sort_five(t_node **stack_a, t_node **stack_b, int argc)
{
	t_node	*start;
	int		*t;

	t = ft_remp(*stack_a, argc);
	start = *stack_a;
	if (t[0] < t[1] && t[0] < t[2] && t[0] < t[3] && t[0] < t[4])
		finish_five(stack_a, stack_b);
	else if (t[1] < t[0] && t[1] < t[2] && t[1] < t[3] && t[1] < t[4])
	{
		swap_a(*stack_a);
		finish_five(stack_a, stack_b);
	}
	else if (t[2] < t[0] && t[2] < t[1] && t[2] < t[3] && t[2] < t[4])
	{
		rotate_a(*stack_a);
		swap_a(*stack_a);
		finish_five(stack_a, stack_b);
	}
	else if (t[3] < t[0] && t[3] < t[1] && t[3] < t[2] && t[3] < t[4])
		last_case(stack_a, 0, stack_b);
	else if (t[4] < t[0] && t[4] < t[1] && t[4] < t[2] && t[4] < t[3])
		last_case(stack_a, 1, stack_b);
	free(t);
}
