/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuller <amuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 21:08:53 by amuller           #+#    #+#             */
/*   Updated: 2022/11/07 21:12:40 by amuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*curr;
	t_list	*temp;

	if (!lst || !(*lst) || !del)
		return ;
	curr = *lst;
	while (curr)
	{
		temp = curr;
		curr = curr->next;
		ft_lstdelone(temp, del);
	}
	*lst = NULL;
}
