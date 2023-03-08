SOURCES =	check_numbers.c number_process.c push_swap.c sort_codes/sort_pivot.c \
			sort_codes/sort_process.c sort_codes/sort_process2.c utils/utils_array.c \
			utils/utils_arrindex.c lib/ft_library.c utils/utils_pushswap.c \
			lib/ft_putstr.c lib/ft_strlen.c

NAME = push_swap

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror $(SOURCES) -o $(NAME)

clean:
	rm $(NAME)

fclean: clean

re: fclean all

git:
	git add .
	git status
	git commit -m "not finished"
	git push

.PHONY:  all clean fclean re git