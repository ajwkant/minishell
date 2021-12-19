NAME = minishell
SRCS =	main.c loop.c  find_path.c error.c is_env_var.c \
		is_simple_command.c \
		builtins/builtin_echo.c builtins/builtin_cd.c \
		builtins/builtin_pwd.c builtins/builtin_env.c
OBJ = $(SRCS:%.c=%.o)
FLAGS = -Wall -Wextra -Werror
LIBFTLIBRARY = ./libft/libft.a

all: $(NAME)

%.o: %.c
	$(CC) -c $(FLAGS) -o $@ $<

$(NAME): $(OBJ)
	$(MAKE) -C ./libft
	$(CC) $(OBJ) $(FLAGS) $(LIBFTLIBRARY) -lreadline -o $(NAME)

clean:
	rm -f *.o
fclean: clean
	rm -f $(NAME)
re: fclean all