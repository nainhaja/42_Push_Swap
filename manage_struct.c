#include "push_swap.h"

t_node	*create_new_node(int value)
{
	t_node	*result;

	result = malloc(sizeof(t_node));
	result->value = value;
	result->next = NULL;
	return (result);
}

t_node	*insert(t_node **head, t_node *node_to_insert)
{
	node_to_insert->next = *head;
	*head = node_to_insert;
	return (node_to_insert);
}

t_node	*copy_final(t_node *stack, t_node *ret, t_node *tmp)
{
	while (stack != NULL)
	{
		if (ret == NULL)
		{
			ret = (t_node *)malloc(sizeof(t_node));
			ret->value = stack->value;
			ret->next = NULL;
			tmp = ret;
		}
		else
		{
			tmp->next = (t_node *)malloc(sizeof(t_node));
			tmp = tmp->next;
			tmp->value = stack->value;
			tmp->next = NULL;
		}
		stack = stack->next;
	}
	return (ret);
}

t_node	*copyList(t_node *stack_a)
{
	t_node	*stack;
	t_node	*newList;
	t_node	*tail;

	stack = stack_a;
	newList = NULL;
	tail = NULL;
	return (copy_final(stack, newList, tail));
}
