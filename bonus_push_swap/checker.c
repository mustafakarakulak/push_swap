/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 12:28:53 by mkarakul          #+#    #+#             */
/*   Updated: 2023/03/14 01:55:25 by mkarakul         ###   ########.fr       */
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

int	init_instructions(t_program *data)
{
	int			ret;
	char		buff[1];

	data->instr = NULL;
	ret = get_instruction(&data->instr);
	while (ret > 0)
		ret = get_instruction(&data->instr);
	if (ret < 0)
	{
		buff[0] = ' ';
		while (buff[0] && read(STDIN_FILENO, &buff, 1))
			;
		free_instructions(data->instr);
		free(data->stack_a.array);
		free(data->stack_b.array);
		write(2, "Error\n", 6);
		return (1);
	}
	return (0);
}

int	main(int ac, char *av[])
{
	t_program		data;

	if (--ac < 1 || ac == 1)
		return (0);
	data.debug = 0;
	if (!ft_strcmp(av[1], "-v"))
	{
		data.debug = 1;
		if (init_stacks(--ac, &av[2], &data.stack_a, &data.stack_b))
			return (1);
	}
	else if (init_stacks(ac, &av[1], &data.stack_a, &data.stack_b))
		return (1);
	if (init_instructions(&data))
		return (1);
	execute_instructions(data.instr, &data.stack_a, &data.stack_b);
	if (is_stack_ordered(&data.stack_a) || data.stack_b.size)
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	return (free_program(&data));
}
