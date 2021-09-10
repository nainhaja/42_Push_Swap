#include "push_swap.h"

void	sort_hundred(t_node **stack_a, t_node **stack_b, int argc)
{
	if (list_size(*stack_a) % 5 == 0)
		ft_sortbig(stack_a, stack_b, argc, 5);
	else if (list_size(*stack_a) % 9 == 0)
		ft_sortbig(stack_a, stack_b, argc, 9);
	else
		ft_sortbig(stack_a, stack_b, argc, 4);
}

void	sort_fiveh(t_node **stack_a, t_node **stack_b, int argc)
{
	if (list_size(*stack_a) % 10 < 3)
		ft_sortbig(stack_a, stack_b, argc, 10);
	else if (list_size(*stack_a) % 10 == 5)
		ft_sortbig(stack_a, stack_b, argc, 15);
	else if (list_size(*stack_a) % 10 >= 6)
		ft_sortbig(stack_a, stack_b, argc, 16);
	else
		ft_sortbig(stack_a, stack_b, argc, 12);
}

void	sort_two(t_node *stack_a)
{
	int	val;
	int	val_2;

	val = stack_a->value;
	val_2 = stack_a->next->value;
	if (val > val_2)
		swap_a(stack_a);
}
