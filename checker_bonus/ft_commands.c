#include "../push_swap.h"

void	rr(t_node *stack_a, t_node *stack_b)
{
	rotate_a(stack_a);
	rotate_b(stack_b);
}

void	rrr(t_node **stack_a, t_node **stack_b)
{
	rrotate_a(stack_a);
	rrotate_b(stack_b);
}

void	ss(t_node *stack_a, t_node *stack_b)
{
	swap_a(stack_a);
	swap_b(stack_b);
}
