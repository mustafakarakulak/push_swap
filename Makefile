SOURCES =	check_numbers.c number_process.c push_swap.c sort_codes/sort_pivot.c \
			sort_codes/sort_process.c sort_codes/sort_process2.c utils/utils_array.c \
			utils/utils_arrindex.c lib/ft_library.c utils/utils_pushswap.c \
			lib/ft_putstr.c lib/ft_strlen.c

BONUS_SRC = push_swap_bonus/check_numbers_bonus.c push_swap_bonus/checker.c \
			push_swap_bonus/number_process_bonus.c push_swap_bonus/utils_generic_bonus.c \
			push_swap_bonus/utils_pushswap_bonus.c push_swap_bonus/utils_array_bonus.c \

NAME = push_swap

B_NAME = checker

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror $(SOURCES) -o $(NAME)

bonus:
	gcc -Wall -Wextra -Werror $(BONUS_SRC) -o $(B_NAME)

clean:
	rm $(NAME) $(B_NAME)

fclean: clean

re: fclean all

git:
	git add .
	git status
	git commit -m "not finished"
	git push

.PHONY:  all clean fclean re git bonus