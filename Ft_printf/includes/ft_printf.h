/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuller <amuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 23:29:17 by amuller           #+#    #+#             */
/*   Updated: 2022/11/21 16:37:04 by amuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define HEX "0123456789abcdef"
# define HEX_UP "0123456789ABCDEF"
# include <unistd.h>
# include <stdarg.h>

typedef struct s_data
{
	int		width;
	int		error;
	int		spaces;
	int		space;
	int		trail;
	int		prec;
	int		zeroes;
	int		zero;
	int		hash;
	int		sign;
	int		dot;
	int		len;
	int		p;
	int		c;
	int		s;
	int		d;
	int		hx;
	int		hxm;
	int		back;
	int		returnerr;
	int		count;
	int		i;
}				t_data;

// FT_PRINTF_C
int		ft_printf(const char *format, ...);
//__attribute__((format (printf, 1, 2)));
void	ft_get_info(const char *format, t_data *data);
void	ft_arg_manager(va_list arg, const char *format, t_data *data);
void	ft_flag(const char *format, t_data *data);
void	ft_precision(const char *format, t_data *data);

//FT_PUT_C
void	ft_printchar(char c, t_data *data);
void	ft_printstr(char *str, t_data *data);
void	ft_put_sign(long n, t_data *data);
void	ft_put_padding(long n, t_data *data);
void	ft_put_trail(t_data *data);

//FT_DIGIT_C
void	ft_get_len_d(long n, t_data *data);
void	ft_putnbr(long n, t_data *data);
void	ft_printnum(long n, t_data *data);

//FT_HEX_C
void	ft_get_len_h(unsigned long n, t_data *data);
void	ft_put_hex(unsigned long n, t_data *data);
void	ft_printhex(unsigned long n, t_data *data);

//LIBFT
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *s, int c, size_t n);
size_t	ft_strlen(const char *s);

#endif
