/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuller <amuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:07:48 by amuller           #+#    #+#             */
/*   Updated: 2022/11/29 15:02:35 by amuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <fcntl.h>
# include <stdarg.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define OPEN_MAX 1048576
# define HEX "0123456789abcdef"
# define HEX_UP "0123456789ABCDEF"

// -------------------------- LIBFT ----------------------------

void	ft_bzero(void *s, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_calloc(size_t count, size_t size);
int		ft_memcmp(const void *s1, const void *s2, size_t n);

int		ft_atoi(const char *nptr);
int		ft_isspace(int c);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_tolower(int c);
int		ft_toupper(int c);

void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strdup(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strcmp(const char *s1, const char *s2);
size_t	ft_strlen(const char *s);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);

char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

// LINKED LIST

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

int		ft_lstsize(t_list *lst);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

// ------------------------ GET_NEXT_LINE --------------------------

char	*ft_realloc(char *line, char *buf);
void	ft_read(char *buf, int fd, ssize_t *needle);

char	*ft_join_gnl(char *line, char *buf, size_t len);
char	*get_next_line(int fd);
ssize_t	ft_next_newline(const char *s);

// -------------------------- FT_PRINTF ----------------------------

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

int		ft_printf(const char *format, ...);
//__attribute__((format (printf, 1, 2)));
void	ft_get_info(const char *format, t_data *data);
void	ft_arg_manager(va_list arg, const char *format, t_data *data);
void	ft_flag(const char *format, t_data *data);
void	ft_precision(const char *format, t_data *data);

void	ft_printchar(char c, t_data *data);
void	ft_printstr(char *str, t_data *data);
void	ft_put_sign(long n, t_data *data);
void	ft_put_padding(long n, t_data *data);
void	ft_put_trail(t_data *data);

void	ft_get_len_d(long n, t_data *data);
void	ft_putnbr(long n, t_data *data);
void	ft_printnum(long n, t_data *data);

void	ft_get_len_h(unsigned long n, t_data *data);
void	ft_put_hex(unsigned long n, t_data *data);
void	ft_printhex(unsigned long n, t_data *data);

#endif
