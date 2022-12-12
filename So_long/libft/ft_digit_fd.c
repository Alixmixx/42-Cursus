/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digit_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuller <amuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 21:05:57 by amuller           #+#    #+#             */
/*   Updated: 2022/12/04 22:30:04 by amuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_get_len_d_fd(long n, t_data *data)
{
	if (n >= 0 && ((data->sign || data->space) && ++data->prec))
		data->len++;
	if (n < 0 && ++data->len && ++data->prec)
		n *= -1;
	while (n > 9 && ++data->len)
		n /= 10;
	++data->len;
	if (data->prec > data->len)
	{
		data->zeroes = data->prec - data->len;
		data->len = data->prec;
	}
}

void	ft_putnb_fd(long n, t_data *data)
{
	if (n < 0)
		n *= -1;
	if (n > 9)
		ft_putnb_fd(n / 10, data);
	ft_printchar_fd((n % 10 + 48), data);
}

void	ft_printnum_fd(long n, t_data *data)
{
	if (data->width || data->dot)
	{
		if (!n && data->sign && data->dot && !data->prec)
			return (data->width--, ft_printstr_fd("", data));
		if (!n && data->dot && !data->width && !data->prec)
			return ;
		if (!n && data->dot && !data->prec)
			return (ft_printstr_fd(" ", data));
		ft_get_len_d_fd(n, data);
	}
	ft_put_padding_fd(n, data);
	ft_putnb_fd(n, data);
}
