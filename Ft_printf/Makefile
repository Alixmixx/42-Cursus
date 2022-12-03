NAME		=	libftprintf.a
CC			=	cc
AR			=	ar -rcs
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f
HEADDIR		=	./includes/
SRCDIR		=	./srcs/
SRCS		=	$(SRCDIR)ft_printf.c\
				$(SRCDIR)ft_put.c\
				$(SRCDIR)ft_digit.c\
				$(SRCDIR)ft_hex.c\
				$(SRCDIR)libft.c\

OBJS		=	$(SRCS:.c=.o)

%.o:		%.c
		$(CC) $(CFLAGS) -I$(HEADDIR) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
		$(AR) -o $(NAME) $(OBJS)

bonus:		all

all:		$(NAME)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:			fclean all

.PHONY:		all re clean fclean bonus
