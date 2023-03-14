/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 12:29:05 by mkarakul          #+#    #+#             */
/*   Updated: 2023/03/14 01:59:08 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <unistd.h>

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
int					init_stacks(int ac, char **av,
						t_stack *stack_a, t_stack *stack_b);
size_t				count_stack_size(int ac, char **av);

void				push_stack(t_stack *stack1, t_stack *stack2);
void				reverse_rotate_stack(t_stack *stack);
void				rotate_stack(t_stack *stack);
void				swap_stack(t_stack *stack);

int					add_instruction(t_instruction **intructions, char *line);
int					get_instruction(t_instruction **instructions);
int					get_instruction2(t_instruction **instructions, char *line);
void				free_instructions(t_instruction *instructions);
void				execute_instructions(t_instruction *instr, t_stack *stack_a,
						t_stack *stack_b);

size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *str);
void				ft_putnbr(int n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_atoi(const char *str, int *num);

void				write_n_char(int n, char c);
int					size_nbr(int n);
int					get_max_size_nbr_stack(t_stack *stack);
int					free_program(t_program *data);

#endif
