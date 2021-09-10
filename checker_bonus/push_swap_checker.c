/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nainhaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 18:10:36 by nainhaja          #+#    #+#             */
/*   Updated: 2021/07/03 18:10:38 by nainhaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_checknum(char **argv, int argc)
{
	int	i;
	int	test;

	i = 1;
	test = 0;
	while (i < argc)
	{
		if (check_number(argv[i]) == 1)
		{
			test = 1;
			break ;
		}	
		i++;
	}
	if (test == 1)
	{
		ft_putstr("Error\n");
		exit(0);
	}
}

void	ft_runcmds(t_node **stack_a, t_node **stack_b, char *str)
{
	if (ft_strcmp(str, "sa") == 0)
		swap_a(*stack_a);
	else if (ft_strcmp(str, "sb") == 0)
		swap_b(*stack_b);
	else if (ft_strcmp(str, "pb") == 0)
		push_b(stack_a, stack_b);
	else if (ft_strcmp(str, "pa") == 0)
		push_a(stack_b, stack_a);
	else if (ft_strcmp(str, "ra") == 0)
		rotate_a(*stack_a);
	else if (ft_strcmp(str, "rra") == 0)
		rrotate_a(stack_a);
	else if (ft_strcmp(str, "rb") == 0)
		rotate_b(*stack_b);
	else if (ft_strcmp(str, "rrb") == 0)
		rrotate_b(stack_b);
	else if (ft_strcmp(str, "rrr") == 0)
		rrr(stack_a, stack_b);
	else if (ft_strcmp(str, "rr") == 0)
		rr(*stack_a, *stack_b);
	else if (ft_strcmp(str, "ss") == 0)
		ss(*stack_a, *stack_b);
}

void	ft_checkcmd(char *str)
{
	int	i;

	i = 0;
	if ((ft_strcmp(str, "sa") == 0) || (ft_strcmp(str, "sb") == 0))
		i = 1;
	else if ((ft_strcmp(str, "ra") == 0) || (ft_strcmp(str, "rb") == 0))
		i = 1;
	else if ((ft_strcmp(str, "rra") == 0) || (ft_strcmp(str, "rrb") == 0))
		i = 1;
	else if ((ft_strcmp(str, "pa") == 0) || (ft_strcmp(str, "pb") == 0))
		i = 1;
	else if (ft_strcmp(str, "ss") == 0)
		i = 1;
	else if (ft_strcmp(str, "rr") == 0)
		i = 1;
	else if (ft_strcmp(str, "rrr") == 0)
		i = 1;
	if (i == 0)
	{
		ft_putstr("Error\n");
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		exit(0);
	ft_checknum(argv, argc);
	insert_tostackk(argc, argv, &stack_a);
	check_duplicate(stack_a);
	ft_checker(&stack_a, &stack_b);
	return (0);
}
