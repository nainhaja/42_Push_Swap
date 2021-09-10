#include "push_swap.h"

void	swap_b(t_node *head)
{
	swap(&head->value, &head->next->value);
	ft_putstr("sb\n");
}

int	get_last(t_node **head)
{
	int		ind;
	t_node	*tmp;

	tmp = *head;
	while (tmp->next != NULL && tmp->next->next != NULL)
		tmp = tmp->next;
	ind = tmp->next->value;
	free(tmp->next);
	tmp->next = NULL;
	return (ind);
}

void	rrotate_a(t_node **head)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	new->value = get_last(head);
	new->next = *head;
	*head = new;
	ft_putstr("rra\n");
}

void	rrotate_b(t_node **head)
{
	t_node	*new;
	t_node	*tmp;

	new = malloc(sizeof(t_node));
	tmp = *head;
	new->value = get_last(head);
	new->next = *head;
	*head = new;
	ft_putstr("rrb\n");
}

void	rotate_a(t_node *head)
{
	t_node	*tmp;

	tmp = head;
	while (tmp != NULL && tmp->next != NULL)
	{
		swap(&tmp->next->value, &tmp->value);
		tmp = tmp->next;
	}
	ft_putstr("ra\n");
}
