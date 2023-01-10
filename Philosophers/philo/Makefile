NAME			=	philo
CC				=	cc
RM				=	rm -f
HEADDIR			=	./includes/
CFLAGS			=	-Werror -Wextra -Wall

SRC_FILES	=	main\
				error\
				get_info\
				init\
				philo\
				mutex\
				time\
				threads\
				check\

HEAD_FILES	=	philo

SRC 			= $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 			= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
HEAD			= $(addprefix $(HEADDIR), $(addsuffix .h, $(HEAD_FILES)))

SRC_DIR		= srcs/
OBJ_DIR		= obj/

OBJ_RESULT = $(OBJ)

END=\033[0m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

OBJ_MKDIR		=	create_dir

all: $(NAME)

$(NAME): $(OBJ_RESULT) $(HEAD)
	@$(CC) $(CFLAGS) $(OBJ_RESULT) -o $@ -I$(HEADDIR)
	@echo "$(GREEN)===============================================$(END)"
	@echo "$(GREEN)|     🧙    Philo compiled finished.    🧙    |$(END)"
	@echo "$(GREEN)===============================================$(END)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_MKDIR)
	@$(CC) $(CFLAGS) -c $^ -o $@ -I$(HEADDIR)
	@echo "$(YELLOW)Compiling... \t$< $(END)"

$(OBJ_MKDIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@$(RM) -rf $(OBJ_DIR)
	@echo "$(MAGENTA)===============================================$(END)"
	@echo "$(MAGENTA)| --    🌪     All objects removed    🌪     -- |$(END)"
	@echo "$(MAGENTA)===============================================$(END)"

fclean:		clean
	@$(RM) -f $(NAME) $(NAME_BONUS)
	@echo "$(RED)===============================================$(END)"
	@echo "$(RED)| --   ❌   All executables removed   ❌   -- |$(END)"
	@echo "$(RED)===============================================$(END)"

scan:
			@scan-build-12 make

re:			fclean all

dirty:
	@make all --no-print-directory
	@make clean --no-print-directory
	@echo "$(BLUE)===============================================$(END)"
	@echo "$(BLUE)| --    🔱    Dirty make finished    🔱    -- |$(END) "
	@echo "$(BLUE)===============================================$(END)"

.PHONY:		all clean fclean re dirty scan
