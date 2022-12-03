NAME		=	push_swap
BNAME	=	checker
LIBFT		=	./libft/libft.a
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f
HEADDIR		=	./includes/
SRCDIR		=	./srcs/
BONUSDIR	=	./bonus/
LIBFTDIR	=	./libft

SRCS		=	$(SRCDIR)main.c\
				$(SRCDIR)move.c\
				$(SRCDIR)small_sort.c\
				$(SRCDIR)sort.c\
				$(SRCDIR)stack_utils.c\
				$(SRCDIR)stack.c\
				$(SRCDIR)tab.c\
				$(SRCDIR)utils.c\

BONUS		=	$(BONUSDIR)main_bonus.c\
				$(BONUSDIR)move_bonus.c\
				$(BONUSDIR)stack_bonus.c\
				$(BONUSDIR)stack_utils_bonus.c\
				$(BONUSDIR)utils_bonus.c\
				$(BONUSDIR)tab_bonus.c\

OBJS			=	$(SRCS:.c=.o)
BONUSOBJS		=	$(BONUS:.c=.o)

%.o:		%.c
		$(CC) $(CFLAGS) -I$(HEADDIR) -c $< -o $(<:.c=.o)

$(NAME):	$(LIBFT) $(OBJS)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -I$(HEADDIR) -L./libft -lft

all:	$(LIBFT) $(NAME)

$(LIBFT):
		@make -C $(LIBFTDIR)

$(BNAME):	$(LIBFT) $(BONUSOBJS)
		$(CC) $(CFLAGS) -o $(BNAME) $(BONUSOBJS) -I$(HEADDIR) -L./libft -lft

bonus:	$(BNAME)

clean:
		$(RM) $(OBJS) $(BONUSOBJS)
		@make clean -C $(LIBFTDIR)

fclean:		clean
		$(RM) $(NAME) $(BNAME)
		@make fclean -C $(LIBFTDIR)

re:			fclean all

.PHONY:		all re clean fclean bonus
