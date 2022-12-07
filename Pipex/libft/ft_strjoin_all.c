/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_all.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuller <amuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:01:24 by amuller           #+#    #+#             */
/*   Updated: 2022/12/01 16:25:13 by amuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_all(size_t str_num, ...)
{
	va_list	arg;
	size_t	i;
	char	*join;
	char	*tmp;
	char	*s;

	i = 0;
	join = NULL;
	va_start(arg, str_num);
	while (i < str_num)
	{
		s = va_arg(arg, char *);
		if (!s)
			return (join);
		tmp = join;
		join = ft_strjoin(join, s);
		free(tmp);
		if (!join)
			return (va_end(arg), NULL);
		i++;
	}
	va_end(arg);
	return (join);
}
