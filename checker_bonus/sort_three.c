#include "../push_swap.h"

void	check_duplicate(t_node *stack_a)
{
	int	size;
	int	i;

	i = 0;
	size = list_size(stack_a);
	while (i < size && stack_a->next != NULL)
	{
		check_value(stack_a->next, stack_a->value);
		stack_a = stack_a->next;
		i++;
	}
}

void	ft_checksorted(t_node *stack_a, t_node *stack_b)
{
	int	flag;

	flag = 0;
	if (stack_a == NULL)
	{
		ft_putstr("KO\n");
		exit(0);
	}
	while (stack_a->next != NULL)
	{
		if (stack_a->value > stack_a->next->value || stack_b != NULL)
			flag = 1;
		stack_a = stack_a->next;
	}
	if (flag == 1)
		ft_putstr("KO\n");
	else
		ft_putstr("OK\n");
}

void	ft_check_last(char c, int flag)
{
	if (c != '\n')
	{
		if (flag != 0)
		{
			ft_putstr("Error\n");
			system("leaks checker");
			exit(0);
		}
	}
}

void	ft_commands(t_node **stack_a, t_node **stack_b, char *str)
{
	if (str == NULL)
	{
		ft_putstr("Error\n");
		exit(0);
	}
	ft_checkcmd(str);
	ft_runcmds(stack_a, stack_b, str);
}

void	ft_checker(t_node **stack_a, t_node **stack_b)
{
	char	c;
	char	*str;
	int		flag;
	char	*test;

	flag = 0;
	str = NULL;
	while (read(0, &c, 1) > 0)
	{
		if (c == '\n')
		{
			ft_commands(stack_a, stack_b, str);
			free(str);
			str = NULL;
		}
		else
		{
			test = str;
			str = ft_strjoin(test, c);
			free(test);
		}
		flag++;
	}
	ft_check_last(c, flag);
	ft_checksorted(*stack_a, *stack_b);
}
