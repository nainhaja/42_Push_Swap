/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nainhaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 17:44:07 by nainhaja          #+#    #+#             */
/*   Updated: 2021/07/12 17:44:09 by nainhaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <limits.h>
# include<stdio.h>

typedef struct t_node
{
	int				value;
	struct t_node	*next;
}				t_node;
long	ft_atoi(char *str);
int		ft_isdigit(char str);
char	*ft_itoa(int a);
void	swap_a(t_node *head);
void	swap_b(t_node *head);
void	rrotate_a(t_node **head);
void	rotate_a(t_node *head);
void	rrotate_b(t_node **head);
void	*swap(int *value1, int *value2);
void	sort_three(t_node **stack_a);
void	sort_four(t_node **stack_a, t_node **stack_b);
void	sort_five(t_node **stack_a, t_node **stack_b, int argc);
void	rotate_b(t_node *head);
void	push_a(t_node **stack_b, t_node **stack_a);
void	push_b(t_node **stack_a, t_node **stack_b);
t_node	*create_new_node(int value);
t_node	*insert(t_node **head, t_node *node_to_insert);
void	quick_sort(t_node *stack_c);
t_node	*copyList(t_node *stack_a);
void	copy_list(t_node *stack_a, t_node *stack_c);
int		get_meduim(int argc, t_node *stack_a, int div);
int		get_indmid(t_node *stack_a, int mid);
int		get_indmid2(t_node *stack_a, int mid);
int		search_max(t_node *stack_b);
int		ft_prep(t_node *stack_a, int argc, int div);
void	return_a(t_node **stack_b, t_node **stack_a, int ind, int argc);
void	return_to_a(t_node **stack_b, int argc, t_node **stack_a);
void	get_data(t_node **stack_a, int mid, int argc, t_node **stack_b);
void	push_rest(t_node **stack_a, t_node **stack_b);
void	insert_tostack(int argc, char **argv, t_node **stack_a);
int		list_size(t_node *stack_a);
void	check_duplicate(t_node *stack_a);
void	ft_putstr(char *str);
int		check_num(char *str);
void	sort_two(t_node *stack_a);
void	sort_hundred(t_node **stack_a, t_node **stack_b, int argc);
void	sort_fiveh(t_node **stack_a, t_node **stack_b, int argc);
void	ft_sortbig(t_node **s_a, t_node **s_b, int argc, int div);
int		ft_strcmp(const char *str, const char *to_find);
char	*ft_strjoin(char *s1, char s2);
size_t	ft_strlen(char *str);
void	ft_checker(t_node **stack_a, t_node **stack_b);
void	ft_runcmds(t_node **stack_a, t_node **stack_b, char *str);
void	ft_checksorted(t_node *stack_a, t_node *stack_b);
void	ft_checkcmd(char *str);
long	ft_espace(const char *str);
void	check_value(t_node *stack_a, int val);
long	ft_nret(char const *str, long cpt, long j);
long	ft_countnb(const char *str, long j);
void	insert_tostackk(int argc, char **argv, t_node **stack_a);
void	ss(t_node *stack_a, t_node *stack_b);
void	rrr(t_node **stack_a, t_node **stack_b);
void	rr(t_node *stack_a, t_node *stack_b);
int		check_number(char *str);

#endif