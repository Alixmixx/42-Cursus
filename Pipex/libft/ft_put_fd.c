/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuller <amuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 23:28:54 by amuller           #+#    #+#             */
/*   Updated: 2022/12/04 22:30:19 by amuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printchar_fd(char c, t_data *data)
{
	data->count += write(data->fd, &c, 1);
}

void	ft_put_trail_fd(t_data *data)
{
	if (data->trail)
		while (data->spaces-- > 0)
			ft_printchar_fd(' ', data);
}

void	ft_printstr_fd(char *str, t_data *data)
{
	if (data->dot && !data->prec && data->s)
		str = NULL;
	if (!str)
	{
		if (!data->dot || data->prec > 5)
			str = "(null)";
		else
			str = "";
	}
	data->len = ft_strlen(str);
	if (data->dot && (data->prec < data->len) && !data->p)
		data->len = data->prec;
	ft_put_padding_fd(0, data);
	data->count += write(data->fd, str, data->len);
}

void	ft_put_sign_fd(long n, t_data *data)
{
	if (data->s)
		return ;
	if (n < 0 && !data->p)
		ft_printchar_fd('-', data);
	else if (data->space)
		ft_printchar_fd(' ', data);
	else if (data->sign && (!data->hash || data->p))
		ft_printchar_fd('+', data);
	if (n && data->hash && data->hxm)
			data->count += write(data->fd, "0X", 2);
	if ((n && data->hash && data->hx) || (n && data->p))
			data->count += write(data->fd, "0x", 2);
}

void	ft_put_padding_fd(long n, t_data *data)
{
	data->spaces = data->width - data->len;
	if ((!data->trail && !data->zero) || (data->zero && data->dot))
		while (data->spaces-- > 0)
			ft_printchar_fd(' ', data);
	ft_put_sign_fd(n, data);
	if (data->width && data->zero && !data->dot)
		while (data->len++ < data->width)
			ft_printchar_fd('0', data);
	if (data->dot)
		while (data->zeroes && data->zeroes--)
			ft_printchar_fd('0', data);
}
