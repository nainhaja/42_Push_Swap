#include "push_swap.h"

void	quick_sort(t_node *stack_c)
{
	int		swapped;
	t_node	*ptr1;
	t_node	*ptr2;

	swapped = 1;
	ptr2 = NULL;
	while (swapped)
	{
		swapped = 0;
		ptr1 = stack_c;
		while (ptr1->next != ptr2)
		{
			if (ptr1->value > ptr1->next->value)
			{
				swap(&ptr1->value, &ptr1->next->value);
				swapped = 1;
			}
			ptr1 = ptr1->next;
		}
		ptr2 = ptr1;
	}
}

void	swap_a(t_node *head)
{
	swap(&head->value, &head->next->value);
	ft_putstr("sa\n");
}

void	last(t_node **stack_a, t_node **stack_b, int flag)
{
	if (flag == 0)
	{
		rrotate_a(stack_a);
		push_b(stack_a, stack_b);
		sort_three(stack_a);
		push_a(stack_b, stack_a);
	}
	else if (flag == 1)
	{
		rotate_a(*stack_a);
		swap_a(*stack_a);
		push_b(stack_a, stack_b);
		sort_three(stack_a);
		push_a(stack_b, stack_a);
	}
	else if (flag == 2)
	{
		swap_a(*stack_a);
		push_b(stack_a, stack_b);
		sort_three(stack_a);
		push_a(stack_b, stack_a);
	}
}

void	sort_four(t_node **stack_a, t_node **stack_b)
{
	int		fr;
	int		sec;
	int		th;
	int		fth;
	t_node	*start;

	start = *stack_a;
	fr = start->value;
	sec = start->next->value;
	th = start->next->next->value;
	fth = start->next->next->next->value;
	if (fr < sec && fr < th && fr < fth)
	{
		push_b(stack_a, stack_b);
		sort_three(stack_a);
		push_a(stack_b, stack_a);
	}
	else if (sec < fr && sec < th && sec < fth)
		last(stack_a, stack_b, 2);
	else if (th < fr && th < sec && th < fth)
		last(stack_a, stack_b, 1);
	else if (fth < fr && fth < sec && fth < th)
		last(stack_a, stack_b, 0);
}
