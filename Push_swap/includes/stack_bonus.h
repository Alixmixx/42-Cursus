/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuller <amuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:08:42 by amuller           #+#    #+#             */
/*   Updated: 2022/11/29 17:46:19 by amuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_BONUS_H
# define STACK_BONUS_H

# define ERROR 0
# define OK 1
# define KO -1
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}				t_stack;

typedef struct s_info
{
	int		*tab;
	char	*move;
	int		len;
}				t_info;

// MOVE_BONUS.C
void	push(t_stack **st1, t_stack **st2);
void	swap(t_stack **st1);
void	rotate(t_stack **st1);
void	rev_rotate(t_stack **st1);

// STACK_BONUS.C
t_stack	*new_stack(void);
int		is_empty_stack(t_stack *st);
int		len_stack(t_stack *st);
t_stack	*add_stack(t_stack *st, int x);
t_stack	*pop_stack(t_stack *st);

// STACK_UTILS_BONUS.C
int		is_sorted_stack(t_stack *st1, int len);
t_stack	*clear_stack(t_stack *st);

t_info	*init(t_stack **a, t_stack **b, int ac, char **av);
int		ft_free(t_stack *a, t_stack *b, t_info *data, int message);
int		ft_read_move(char *line, t_info *data);
int		ft_make_move(t_stack **a, t_stack **b, t_info *data);

// UTILS_BONUS.C
int		ft_free(t_stack *a, t_stack *b, t_info *data, int message);
int		ft_read_move(char *line, t_info *data);
int		ft_make_move(t_stack **a, t_stack **b, t_info *data);
int		ft_check_moves(t_stack *a, t_stack *b, t_info *data);

// TAB_BONUS.C
void	ft_free_tab(char **tab);
int		ft_tab_len(char **tab);
int		*create_tab(char **av, int len);
int		ft_num(char *s);
int		check_duplicate(int *tab, int len);

#endif
