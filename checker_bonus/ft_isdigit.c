/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nainhaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 16:21:10 by nainhaja          #+#    #+#             */
/*   Updated: 2019/10/16 16:24:54 by nainhaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

void	ft_checklastnb(int j, int minus, int plus, char *str)
{
	if (j > 10 && str[0] != '-' && str[0] != '+')
	{
		ft_putstr("Error\n");
		exit(0);
	}
	else if (j > 11 && (minus > 0 || plus > 0))
	{
		ft_putstr("Error\n");
		exit(0);
	}
}

int	ft_checksigns(int *minus, int *plus, char *str, int j)
{
	int	flag;

	flag = 0;
	if (str[j] != '-' && str[j] != '+')
	{			
		if (ft_isdigit(str[j]) == 0)
		{
			flag = 1;
			return (1);
		}
	}
	else if (*minus == 0 && str[j] == '-' && j == 0)
		*minus = 1;
	else if (*plus == 0 && str[j] == '+' && j == 0)
		*plus = 1;
	else if (j > 0)
	{
		flag = 1;
		return (1);
	}
	return (0);
}

int	ft_flag(char *str, int flag, int minus)
{
	int	j;
	int	plus;

	j = 0;
	plus = 0;
	flag = 0;
	while (str[j])
	{
		if (ft_checksigns(&minus, &plus, str, j) == 1)
		{
			flag = 1;
			break ;
		}
		j++;
	}
	ft_checklastnb(j, minus, plus, str);
	if (j == 1 && (plus > 0 || minus > 0))
		flag = 1;
	return (flag);
}

int	check_number(char *str)
{
	int	flag;
	int	test;
	int	minus;

	test = 1;
	flag = 0;
	minus = 0;
	return (ft_flag(str, flag, minus));
}
