#include "../push_swap.h"

void	swap_b(t_node *head)
{
	if ((head == NULL) || (head->next == NULL))
		return ;
	swap(&head->value, &head->next->value);
}

int	get_last(t_node **head)
{
	int		ind;
	t_node	*tmp;

	tmp = *head;
	while (tmp->next != NULL && tmp->next->next != NULL)
	{
		tmp = tmp->next;
	}
	ind = tmp->next->value;
	free(tmp->next);
	tmp->next = NULL;
	return (ind);
}

void	rrotate_a(t_node **head)
{
	t_node	*new;

	if ((*head) == NULL || ((*head)->next == NULL))
		return ;
	new = malloc(sizeof(t_node));
	new->value = get_last(head);
	new->next = *head;
	*head = new;
}

void	rrotate_b(t_node **head)
{
	t_node	*new;
	t_node	*tmp;

	if ((*head) == NULL || ((*head)->next == NULL))
		return ;
	new = malloc(sizeof(t_node));
	tmp = *head;
	new->value = get_last(head);
	new->next = *head;
	*head = new;
}

void	rotate_a(t_node *head)
{
	t_node	*tmp;

	if ((head) == NULL || (head->next == NULL))
		return ;
	tmp = head;
	while (tmp != NULL && tmp->next != NULL)
	{
		swap(&tmp->next->value, &tmp->value);
		tmp = tmp->next;
	}
}
