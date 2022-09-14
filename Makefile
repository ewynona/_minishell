NAME	=	minishell

INC		=	include/

SRC		=	termcap/main.c \
			termcap/get_next_input_line.c \
			termcap/termcap_utils.c \
			termcap/key_utils.c \
			termcap/key_utils1.c \
			termcap/history_list.c \
			termcap/history_file.c \
			termcap/signals.c \
			parser/parse_chars.c \
			parser/parse_env.c \
			parser/parse_fd.c \
			parser/parse_quotes.c \
			parser/str_check_1.c \
			parser/str_check_2.c \
			parser/str_parser.c \
			logic/builtin_cd.c \
			logic/builtin_echo.c \
			logic/builtin_env.c \
			logic/builtin_exit.c \
			logic/builtin_export.c \
			logic/builtin_pwd.c \
			logic/builtin_unset.c \
			logic/cmd_init.c \
			logic/command_call.c \
			logic/environment_proc_1.c \
			logic/environment_proc_2.c \
			logic/find_exec_path.c \
			logic/free_lst.c \
			logic/pipe_proc.c \
			logic/utils.c \
			logic/utils_for_pipe.c

CFLAGS = -Wall -Wextra -Werror -g

OBJ = $(SRC:.c=.o)

%.o: %.c $(INC)
	@gcc  $(CFLAGS) -I $(INC) -c $< -o $@
	@echo "compiling" $<

all: 
		$(MAKE) $(NAME) -j 4

${NAME}: $(OBJ)
	@echo "_________________________"
	@$(MAKE) -C libft/
	@gcc $(CFLAGS) $(OBJ) -I $(INC) -L./libft -lft -ltermcap -o $(NAME)

clean:
	@$(MAKE) clean -C libft/
	@rm -rf $(OBJ)
	@echo "minishell clean"

fclean:
	@$(MAKE) fclean -C libft/
	@rm -rf $(OBJ) minishell
	@echo "minishell fclean"

re: fclean all

norma:
	@echo "******** minishell **********"
	@norminette parser/*.c logic/*.c termcap/*.c include/*.h
	@echo "********** libft ************"
	@norminette libft/*.c libft/*.h

.PHONY: all, clean, fclean, re, norma

