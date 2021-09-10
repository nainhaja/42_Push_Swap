#include "push_swap.h"

void	*swap(int *value1, int *value2)
{
	int	tmp;

	tmp = *value2;
	*value2 = *value1;
	*value1 = tmp;
	return (0);
}

void	rotate_b(t_node *head)
{
	t_node	*tmp;

	tmp = head;
	while (tmp != NULL && tmp->next != NULL)
	{
		swap(&tmp->next->value, &tmp->value);
		tmp = tmp->next;
	}
	ft_putstr("rb\n");
}

void	push_a(t_node **stack_b, t_node **stack_a)
{
	t_node	*tmp_b;
	t_node	*tmp_2;
	t_node	*tmp_3;

	if (*(stack_b) == NULL)
		return ;
	tmp_b = *stack_b;
	tmp_2 = malloc(sizeof(t_node));
	tmp_3 = tmp_b;
	tmp_2->value = tmp_b->value;
	*stack_b = tmp_b->next;
	tmp_2->next = *stack_a;
	*stack_a = tmp_2;
	free(tmp_3);
	ft_putstr("pa\n");
}

void	push_b(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp_a;
	t_node	*tmp_2;
	t_node	*tmp_3;

	if (*(stack_a) == NULL)
		return ;
	tmp_a = *stack_a;
	tmp_2 = malloc(sizeof(t_node));
	tmp_3 = tmp_a;
	tmp_2->value = tmp_a->value;
	tmp_2->next = *stack_b;
	*stack_b = tmp_2;
	*stack_a = tmp_a->next;
	free(tmp_3);
	ft_putstr("pb\n");
}
