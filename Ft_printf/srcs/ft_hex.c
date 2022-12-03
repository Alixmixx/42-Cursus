/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuller <amuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 21:05:57 by amuller           #+#    #+#             */
/*   Updated: 2022/11/21 19:55:31 by amuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_get_len_h(unsigned long n, t_data *data)
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

void	ft_put_hex(unsigned long n, t_data *data)
{
	if (n > 15)
		ft_put_hex(n / 16, data);
	ft_printchar(HEX[n % 16] * data->hx + HEX_UP[n % 16] * data->hxm, data);
}

void	ft_printhex(unsigned long n, t_data *data)
{
	if (data->p && !n)
		return (ft_printstr("(nil)", data));
	if (data->width || data->dot)
	{
		ft_get_len_h(n, data);
		if (!n && data->dot && !data->width && !data->prec)
			return ;
		if (!n && data->dot && !data->prec)
			return (ft_printstr(" ", data));
	}
	ft_put_padding(n, data);
	ft_put_hex(n, data);
}
