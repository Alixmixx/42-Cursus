NAME		=	pipex
LIBFT		=	./libft/libft.a
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f
HEADDIR		=	./includes/
SRCDIR		=	./srcs/
LIBFTDIR	=	./libft

GREEN=\033[0;32m
RED=\033[0;31m
YELLOW=\033[0;43m
PINK=\033[0;35m
BLUE=\033[0;34m
END=\033[0m

SRCS		+=	$(SRCDIR)main.c
SRCS		+=	$(SRCDIR)utils.c
SRCS		+=	$(SRCDIR)here_doc.c
SRCS		+=	$(SRCDIR)free.c
SRCS		+=	$(SRCDIR)pipes.c
SRCS		+=	$(SRCDIR)error.c


OBJS			=	$(SRCS:.c=.o)

%.o:		%.c
		@$(CC) $(CFLAGS) -I$(HEADDIR) -c $< -o $(<:.c=.o)


$(NAME):	$(LIBFT) $(OBJS)
		@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -I$(HEADDIR) -L./libft -lft
		@echo "	🦀  $(GREEN)-- $(NAME) compiled --$(END) 🦀"

all:	$(LIBFT) $(NAME)

$(LIBFT):
		@make -C $(LIBFTDIR) --no-print-directory
		@echo "	🦀  $(GREEN)-- libft compiled --$(END) 🦀"

bonus:	$(NAME)

clean:
		@$(RM) $(OBJS)
		@make clean -C $(LIBFTDIR) --no-print-directory
		@echo "	$(PINK)--   All objects removed   --$(END) 🌪"

fclean:		clean
		@$(RM) $(NAME)
		@make fclean -C $(LIBFTDIR) --no-print-directory
		@echo "	$(RED)-- All executables removed --$(END) ❌"

scan:
		@echo "	$(PINK)-- Scan-build running --$(END) 👀"
		@scan-build-12 make --no-print-directory
		@echo "	$(GREEN)--    Scan finished   --$(END) 🔍"

re:			fclean all

.PHONY:		all re clean fclean bonus scan
