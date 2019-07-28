NAME = schornon.filler

SRCS = main.c struct_cntrl.c ft_join_pf.c map_make.c piece_make.c algo.c algo_add.c eval.c gnl/get_next_line.c

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	@make -C libft/
	@gcc -o $(NAME) $(SRCS) $(FLAGS) libft/libft.a

clean:
	@make clean -C libft

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)

re: fclean all
