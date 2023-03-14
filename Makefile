SOURCES =	check_numbers.c number_process.c push_swap.c sort_codes/sort_pivot.c \
			sort_codes/sort_process.c sort_codes/sort_process2.c utils/utils_array.c \
			utils/utils_arrindex.c lib/ft_library.c utils/utils_pushswap.c \
			lib/ft_putstr.c lib/ft_strlen.c

BONUS_SRC =		bonus_push_swap/checker.c \
				bonus_push_swap/init_stacks.c \
				bonus_push_swap/operations.c \
				bonus_push_swap/instructions.c \
				bonus_push_swap/utils.c \
				bonus_push_swap/debug.c \
				bonus_push_swap/instructions2.c

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