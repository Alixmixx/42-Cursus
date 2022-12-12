/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuller <amuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 23:28:33 by amuller           #+#    #+#             */
/*   Updated: 2022/12/06 20:52:15 by amuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_arg_manager_fd(va_list arg, const char *format, t_data *data)
{
	if (*format == 'c' && ++data->c && ++data->len)
	{
		ft_put_padding_fd(0, data);
		ft_printchar_fd(va_arg(arg, int), data);
	}
	else if (*format == 's' && ++data->s)
		ft_printstr_fd(va_arg(arg, char *), data);
	else if (*format == 'p' && ++data->p && ++data->hx)
		ft_printhex_fd(va_arg(arg, unsigned long), data);
	else if ((*format == 'd' || *format == 'i') && ++data->d)
		ft_printnum_fd(va_arg(arg, int), data);
	else if (*format == 'u' && ++data->d)
		ft_printnum_fd(va_arg(arg, unsigned int), data);
	else if (*format == 'x' && ++data->hx)
		ft_printhex_fd(va_arg(arg, unsigned int), data);
	else if (*format == 'X' && ++data->hxm)
		ft_printhex_fd(va_arg(arg, unsigned int), data);
	else if (*format == '%')
		ft_printchar_fd('%', data);
	else if (!*format && ++data->returnerr)
		return ;
	else if (++data->error)
		return ;
	ft_put_trail_fd(data);
	data->i++;
}

void	ft_flag_fd(const char *format, t_data *data)
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

void	ft_precision_fd(const char *format, t_data *data)
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

void	ft_get_info_fd(const char *format, t_data *data)
{
	data->i++;
	data->back = data->i;
	ft_bzero(data, sizeof(*data) - sizeof(int) * 3);
	ft_flag_fd(format + data->i, data);
	ft_precision_fd(format + data->i, data);
}

int	ft_printf_fd(int fd, const char *format, ...)
{
	t_data	data;
	va_list	arg;

	if (!format)
		return (-1);
	ft_bzero(&data, sizeof(data));
	data.fd = fd;
	va_start(arg, format);
	while (format && format[data.i])
	{
		if (format[data.i] == '%' && ((!data.error && --data.error)))
		{
			ft_get_info_fd(format, &data);
			ft_arg_manager_fd(arg, format + data.i, &data);
			if (data.error)
				data.i = data.back;
		}
		else
			ft_printchar_fd(format[data.i++], &data);
	}
	va_end(arg);
	if (data.returnerr)
		return (-1);
	return (data.count);
}
