/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 12:29:05 by mkarakul          #+#    #+#             */
/*   Updated: 2023/03/14 01:43:38 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <unistd.h>

# define _END		"\x1b[0m"
# define _RED		"\x1b[31m"
# define _YELLOW	"\x1b[33m"
# define _GREEN		"\x1b[32m"

# ifndef DEBUG
#  define DEBUG 0
# endif

typedef struct s_stack
{
	int				*array;
	size_t			size;
}					t_stack;

typedef struct s_instruction
{
	char			*line;
	void			*next;
}					t_instruction;

typedef struct s_program
{
	t_stack			stack_a;
	t_stack			stack_b;
	t_instruction	*instr;
	int				debug;
}					t_program;

int					stack_contains(t_stack *stack, int num);
int					int_stacks_2(int ac, char **av,
						t_stack *stack_a, t_stack *stack_b);

int					init_stacks(int ac, char *av[],
						t_stack *stack_a, t_stack *stack_b);

void				reverse_rotate_stack(t_stack *stack);
void				rotate_stack(t_stack *stack);
void				push_stack(t_stack *stack1, t_stack *stack2);
void				swap_stack(t_stack *stack);
size_t				count_stack_size(int ac, char *av[]);

void				free_instructions(t_instruction *instructions);
void				execute_instructions(t_instruction *instr, t_stack *stack_a,
						t_stack *stack_b);
int					add_instruction(t_instruction **intructions, char *line);
int					get_instruction(t_instruction **instructions);
int					get_instruction2(t_instruction **instructions, char *line);

int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strdup(const char *str);
size_t				ft_strlen(const char *s);
void				ft_putnbr(int n);
int					ft_atoi(const char *str, int *num);

void				write_n_char(int n, char c);
int					size_nbr(int n);
int					get_max_size_nbr_stack(t_stack *stack);
int					free_prg(t_program *prg);

#endif
