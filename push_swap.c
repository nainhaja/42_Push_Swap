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

#include "push_swap.h"

void	ft_sortbig(t_node **s_a, t_node **s_b, int argc, int div)
{
	int		plus;
	int		mid;
	int		ind;
	int		end;

	ind = ((argc - 1) / div);
	plus = argc / div;
	end = 0;
	while (plus <= argc - 1)
	{
		mid = ft_prep(*s_a, argc, div);
		while (end < plus)
		{
			get_data(s_a, mid, argc - end - 1, s_b);
			end++;
		}
		plus = ind + plus;
	}
	if (list_size(*s_a) % div != 0 )
		push_rest(s_a, s_b);
	return_to_a(s_b, argc, s_a);
}

void	check_sorted(t_node *stack_a)
{
	int	flag;

	flag = 0;
	while (stack_a->next != NULL)
	{
		if (stack_a->value > stack_a->next->value)
			flag = 1;
		stack_a = stack_a->next;
	}
	if (flag == 0)
		exit(0);
}

void	ft_checknum(char **argv, int argc)
{
	int	i;
	int	test;

	i = 1;
	test = 0;
	while (i < argc)
	{
		if (check_num(argv[i]) == 1)
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

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;

	if (argc == 1)
		exit(0);
	stack_a = NULL;
	stack_b = NULL;
	ft_checknum(argv, argc);
	insert_tostack(argc, argv, &stack_a);
	check_duplicate(stack_a);
	check_sorted(stack_a);
	if (argc == 3)
		sort_two(stack_a);
	else if (argc == 4)
		sort_three(&stack_a);
	else if (argc == 5)
		sort_four(&stack_a, &stack_b);
	else if (argc == 6)
		sort_five(&stack_a, &stack_b, argc);
	else if (argc < 102 && argc > 6)
		sort_hundred(&stack_a, &stack_b, argc);
	else if (argc < 502 && argc >= 102)
		sort_fiveh(&stack_a, &stack_b, argc);
	return (0);
}
