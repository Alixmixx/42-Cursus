NAME		=	so_long
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -g
RM			=	rm -f
HEADDIR		=	./includes/
SRCDIR		=	./srcs/
LIBDIR		=	./lib
LIBFTDIR	=	./libft
LIBFT		=	./libft/libft.a
LIBS		=	-lmlx -lXext -lX11 -lft

GREEN=\033[0;32m
RED=\033[0;31m
YELLOW=\033[0;43m
PINK=\033[0;35m
BLUE=\033[0;34m
END=\033[0m

SRCS		=	$(SRCDIR)main.c\
				$(SRCDIR)map.c\
				$(SRCDIR)read_map.c\
				$(SRCDIR)map_checker.c\
				$(SRCDIR)maze.c\
				$(SRCDIR)input.c\
				$(SRCDIR)image.c\
				$(SRCDIR)render.c\
				$(SRCDIR)error.c\
				$(SRCDIR)fly.c\

OBJS		=	$(SRCS:.c=.o)

%.o:		%.c
		@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I$(HEADDIR) -L$(LIBDIR) -L$(LIBFTDIR) $(LIBS)

$(NAME):	$(LIBFT) $(OBJS)
		@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -I$(HEADDIR) -L$(LIBDIR) -L$(LIBFTDIR) $(LIBS)
		@echo "	🕹  $(GREEN)-- $(NAME) compiled --$(END) 🕹"

all:	$(LIBFT) $(NAME)

$(LIBFT):
		@make -C $(LIBFTDIR) --no-print-directory
		@echo "	🦀 $(GREEN)--  libft compiled  --$(END) 🦀"

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
