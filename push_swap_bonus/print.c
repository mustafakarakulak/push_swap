/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 15:28:05 by mkarakul          #+#    #+#             */
/*   Updated: 2023/03/13 22:44:58 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	print_bottom_stack(int max_size_nbr[2])
{
	write(1, "	", 1);
	write_n_char(max_size_nbr[0], '_');
	write(1, " ", 1);
	write_n_char(max_size_nbr[1], '_');
	write(1, "\n", 1);
	write(1, "	", 1);
	write_n_char(max_size_nbr[0] - 1, ' ');
	write(1, "a ", 2);
	write_n_char(max_size_nbr[1] - 1, ' ');
	write(1, "b", 1);
	write(1, "\n", 1);
}

void	print_numbers_stacks(int max_size, int max_size_nbr[2],
t_stack *stack_a, t_stack *stack_b)
{
	int		i;

	i = -1;
	while (++i < max_size)
	{
		write(1, "	", 1);
		if ((int)(stack_a->size - max_size + i) >= 0)
			write_n_char(max_size_nbr[0]
				- size_nbr(stack_a->array[stack_a->size - max_size + i]), ' ');
		if ((int)(stack_a->size - max_size + i) >= 0)
			ft_putnbr(stack_a->array[stack_a->size - max_size + i]);
		else
			write_n_char(max_size_nbr[0], ' ');
		write(1, " ", 1);
		if ((int)(stack_b->size - max_size + i) >= 0)
			write_n_char(max_size_nbr[1]
				- size_nbr(stack_b->array[stack_b->size - max_size + i]), ' ');
		if ((int)(stack_b->size - max_size + i) >= 0)
			ft_putnbr(stack_b->array[stack_b->size - max_size + i]);
		else
			write_n_char(max_size_nbr[1], ' ');
		write(1, "\n", 1);
	}
}

void	print_stacks(t_stack *stack_a, t_stack *stack_b)
{
	int		max_size_nbr[2];
	int		max_size;

	max_size = stack_a->size;
	if (stack_b->size > stack_a->size)
		max_size = stack_b->size;
	write(1, _YELLOW, ft_strlen(_YELLOW));
	write(1, "stacks\n", 7);
	write(1, _END, ft_strlen(_END));
	max_size_nbr[0] = get_max_size_nbr_stack(stack_a);
	max_size_nbr[1] = get_max_size_nbr_stack(stack_b);
	print_numbers_stacks(max_size, max_size_nbr, stack_a, stack_b);
	print_bottom_stack(max_size_nbr);
}

void	print_instructions(t_instruction *instructions)
{
	write(1, _YELLOW, ft_strlen(_YELLOW));
	write(1, "instructions\n", 13);
	write(1, _END, ft_strlen(_END));
	while (instructions)
	{
		write(1, "	", 1);
		write(1, instructions->line, ft_strlen(instructions->line));
		write(1, "\n", 1);
		instructions = instructions->next;
	}
}

void	print_debug_instruction(t_instruction *instr,
			t_stack *stack_a, t_stack *stack_b)
{
	write(1, "---\n", 4);
	write(1, _YELLOW, ft_strlen(_YELLOW));
	write(1, "do	", 3);
	write(1, _END, ft_strlen(_END));
	write(1, instr->line, ft_strlen(instr->line));
	write(1, "\n", 1);
	print_stacks(stack_a, stack_b);
}
