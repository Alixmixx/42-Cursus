/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuller <amuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 21:05:57 by amuller           #+#    #+#             */
/*   Updated: 2022/12/04 22:30:07 by amuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_get_len_h_fd(unsigned long n, t_data *data)
{
	if (n && (data->hash || data->p))
	{
		data->len += 2;
		data->prec += 2;
	}
	while (n > 15 && ++data->len)
		n /= 16;
	++data->len;
	if (data->prec > data->len)
	{
		data->zeroes = data->prec - data->len;
		data->len = data->prec;
	}
}

void	ft_put_hex_fd(unsigned long n, t_data *data)
{
	if (n > 15)
		ft_put_hex_fd(n / 16, data);
	ft_printchar_fd(HEX[n % 16] * data->hx + HEX_UP[n % 16] * data->hxm, data);
}

void	ft_printhex_fd(unsigned long n, t_data *data)
{
	if (data->p && !n)
		return (ft_printstr_fd("(nil)", data));
	if (data->width || data->dot)
	{
		ft_get_len_h_fd(n, data);
		if (!n && data->dot && !data->width && !data->prec)
			return ;
		if (!n && data->dot && !data->prec)
			return (ft_printstr_fd(" ", data));
	}
	ft_put_padding_fd(n, data);
	ft_put_hex_fd(n, data);
}
