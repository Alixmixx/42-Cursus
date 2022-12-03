/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuller <amuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:08:42 by amuller           #+#    #+#             */
/*   Updated: 2022/11/28 14:29:39 by amuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stdlib.h>
# include <stdio.h>
# include "libft.h"

typedef struct s_stack
{
	int				value;
	int				key;
	struct s_stack	*next;
}				t_stack;

typedef struct s_info
{
	int		*tab;
	int		*sort_tab;
	int		len;
	int		chunk;
	int		size;
	int		num;
}				t_info;

// STACK.C
t_stack	*new_stack(void);
int		is_empty_stack(t_stack *st);
int		len_stack(t_stack *st);
t_stack	*stack_last(t_stack *st);
t_stack	*stack_at(t_stack *st, int x);

// STACK_UTILS.C
t_stack	*add_stack(t_stack *st, t_info *data, int x);
t_stack	*pop_stack(t_stack *st);
int		is_rev_sorted_stack(t_stack *st1, int len);
int		is_sorted_stack(t_stack *st1, int len);
t_stack	*clear_stack(t_stack *st);

// MOVE.C
void	push(t_stack **st1, t_stack **st2);
void	swap(t_stack **st1);
void	rotate(t_stack **st1);
void	rev_rotate(t_stack **st1);

//	SORT.C
void	split_sort(t_stack **a, t_stack **b, t_info *data);
void	sort_back(t_stack **a, t_stack **b, t_info *data);

// UTILS.C
int		ft_num(char *s);
int		check_duplicate(int *tab, int len);
int		get_key(t_info *data, int value);

// SMALL_SORT.C
void	small_sort(t_stack **a, t_stack **b, t_info *data);
void	rev_sort_3(t_stack **b);
void	sort_3(t_stack **a);
void	get_small_top(t_stack **a, int index);
void	push_smaller(t_stack **a, t_stack **b, t_info *data);

// TAB.C
void	ft_free_tab(char **tab);
int		ft_tab_len(char **tab);
int		*create_tab(char **av, int len);
void	sort_tab(int *tab, int len);

#endif
