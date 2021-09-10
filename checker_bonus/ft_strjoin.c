/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nainhaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 17:43:14 by nainhaja          #+#    #+#             */
/*   Updated: 2021/06/30 17:43:16 by nainhaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_isdigit(char str)
{
	if (str >= '0' && str <= '9')
		return (1);
	else
		return (0);
}

void	swap_a(t_node *head)
{
	if ((head) == NULL || (head->next == NULL))
		return ;
	swap(&head->value, &head->next->value);
}

static char	*ft_remplir(char *s1, char s2, char *ret)
{
	int	i;
	int	j;
	int	k;

	k = 0;
	j = 0;
	i = 0;
	while (s1[i] != '\0')
	{
		ret[k] = s1[i];
		k++;
		i++;
	}
	ret[k] = s2;
	ret[k + 1] = '\0';
	return (ret);
}

char	*ft_strjoin(char *s1, char s2)
{
	char	*ret;
	int		flag;

	flag = 0;
	if (s2 == '\0')
	{
		ft_putstr("Error\n");
		exit(0);
	}
	if (s1 == NULL)
	{
		s1 = malloc(sizeof(char) * 1);
		s1[0] = '\0';
		flag = 1;
	}
	ret = (char *)malloc(ft_strlen(s1) + 2);
	if (ret)
	{
		ret = ft_remplir(s1, s2, ret);
		if (flag == 1)
			free(s1);
		return (ret);
	}
	else
		return (0);
}
