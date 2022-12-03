/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuller <amuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 23:28:33 by amuller           #+#    #+#             */
/*   Updated: 2022/11/23 13:21:17 by amuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_arg_manager(va_list arg, const char *format, t_data *data)
{
	if (*format == 'c' && ++data->c && ++data->len)
	{
		ft_put_padding(0, data);
		ft_printchar(va_arg(arg, int), data);
	}
	else if (*format == 's' && ++data->s)
		ft_printstr(va_arg(arg, char *), data);
	else if (*format == 'p' && ++data->p && ++data->hx)
		ft_printhex(va_arg(arg, unsigned long), data);
	else if ((*format == 'd' || *format == 'i') && ++data->d)
		ft_printnum(va_arg(arg, int), data);
	else if (*format == 'u' && ++data->d)
		ft_printnum(va_arg(arg, unsigned int), data);
	else if (*format == 'x' && ++data->hx)
		ft_printhex(va_arg(arg, unsigned int), data);
	else if (*format == 'X' && ++data->hxm)
		ft_printhex(va_arg(arg, unsigned int), data);
	else if (*format == '%')
		ft_printchar('%', data);
	else if (!*format && ++data->returnerr)
		return ;
	else if (++data->error)
		return ;
	ft_put_trail(data);
	data->i++;
}

void	ft_flag(const char *format, t_data *data)
{
	while (*format == '-' || *format == '+' || *format == '0'
		|| *format == '#' || *format == ' ')
	{
		if (*format == '-' && format++ && data->i++)
			data->trail = 1;
		else if (*format == '+' && format++ && data->i++)
			data->sign = 1;
		else if (*format == '0' && format++ && data->i++)
			data->zero = 1;
		else if (*format == '#' && format++ && data->i++)
			data->hash = 1;
		else if (*format == ' ' && format++ && data->i++)
			data->space = 1;
		else
			return ;
	}
}

void	ft_precision(const char *format, t_data *data)
{
	while (*format >= '0' && *format <= '9')
	{
		data->width *= 10;
		data->width += *format - 48;
		format++;
		data->i++;
	}
	if (*format == '.' && ++data->dot && format++ && ++data->i)
	{
		while (*format >= '0' && *format <= '9')
		{
			data->prec *= 10;
			data->prec += *format - 48;
			format++;
			data->i++;
		}
	}
}

void	ft_get_info(const char *format, t_data *data)
{
	data->i++;
	data->back = data->i;
	ft_bzero(data, sizeof(*data) - sizeof(int) * 2);
	ft_flag(format + data->i, data);
	ft_precision(format + data->i, data);
}

int	ft_printf(const char *format, ...)
{
	t_data	data;
	va_list	arg;

	if (!format)
		return (-1);
	ft_bzero(&data, sizeof(data));
	va_start(arg, format);
	while (format && format[data.i])
	{
		if (format[data.i] == '%' && ((!data.error && --data.error)))
		{
			ft_get_info(format, &data);
			ft_arg_manager(arg, format + data.i, &data);
			if (data.error)
				data.i = data.back;
		}
		else
			ft_printchar(format[data.i++], &data);
	}
	va_end(arg);
	if (data.returnerr)
		return (-1);
	return (data.count);
}
