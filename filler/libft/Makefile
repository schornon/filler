NAME=libft.a
FILES= *.c 
OBJECTS= *.o
all: $(NAME)

$(NAME):
	@gcc -Wall -Wextra -Werror -c $(FILES)
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)
clean:
	@rm -f $(OBJECTS)
fclean: clean
	@rm -f $(NAME)
re: fclean all