/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 12:28:53 by mkarakul          #+#    #+#             */
/*   Updated: 2023/03/14 01:20:27 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	is_stack_ordered(t_stack *stack)
{
	size_t	i;

	i = 0;
	while (i < stack->size - 1)
	{
		if (stack->array[i] >= stack->array[i + 1])
			return (1);
		i++;
	}
	return (0);
}

int	stack_contains(t_stack *stack, int num)
{
	size_t	i;

	i = 0;
	while (i < stack->size)
	{
		if (stack->array[i++] == num)
			return (1);
	}
	return (0);
}

int	init_instructions(t_program *prg)
{
	int			ret;
	char		buff[1];

	prg->instr = NULL;
	ret = get_instruction(&prg->instr);
	while (ret > 0)
		ret = get_instruction(&prg->instr);
	if (ret < 0)
	{
		buff[0] = ' ';
		while (buff[0] && read(STDIN_FILENO, &buff, 1))
			;
		free_instructions(prg->instr);
		free(prg->stack_a.array);
		free(prg->stack_b.array);
		write(2, "Error\n", 6);
		return (1);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_program		prg;

	if (--argc < 1 && argc == 1)
		return (0);
	prg.debug = 0;
	if (!ft_strcmp(argv[1], "-v"))
	{
		prg.debug = 1;
		if (init_stacks(--argc, &argv[2], &prg.stack_a, &prg.stack_b))
			return (1);
	}
	else if (init_stacks(argc, &argv[1], &prg.stack_a, &prg.stack_b))
		return (1);
	if (init_instructions(&prg))
		return (1);
	if (prg.debug)
		print_instructions(prg.instr);
	if (prg.debug)
		print_stacks(&prg.stack_a, &prg.stack_b);
	execute_instructions(prg.instr, &prg.stack_a, &prg.stack_b, prg.debug);
	if (is_stack_ordered(&prg.stack_a) || prg.stack_b.size)
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	return (free_prg(&prg));
}
