/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 17:11:04 by mkarakul          #+#    #+#             */
/*   Updated: 2023/03/14 01:38:47 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	free_instructions(t_instruction *instructions)
{
	t_instruction	*next;

	while (instructions)
	{
		next = instructions->next;
		free(instructions->line);
		free(instructions);
		instructions = next;
	}
}

void	execute_instructions(t_instruction *instr, t_stack *stack_a,
	t_stack *stack_b)
{
	while (instr)
	{
		if (!ft_strcmp(instr->line, "sa") || !ft_strcmp(instr->line, "ss"))
			swap_stack(stack_a);
		if (!ft_strcmp(instr->line, "sb") || !ft_strcmp(instr->line, "ss"))
			swap_stack(stack_b);
		if (!ft_strcmp(instr->line, "pa"))
			push_stack(stack_a, stack_b);
		if (!ft_strcmp(instr->line, "pb"))
			push_stack(stack_b, stack_a);
		if (!ft_strcmp(instr->line, "ra") || !ft_strcmp(instr->line, "rr"))
			rotate_stack(stack_a);
		if (!ft_strcmp(instr->line, "rb") || !ft_strcmp(instr->line, "rr"))
			rotate_stack(stack_b);
		if (!ft_strcmp(instr->line, "rra") || !ft_strcmp(instr->line, "rrr"))
			reverse_rotate_stack(stack_a);
		if (!ft_strcmp(instr->line, "rrb") || !ft_strcmp(instr->line, "rrr"))
			reverse_rotate_stack(stack_b);
		instr = instr->next;
	}
}

int	add_instruction(t_instruction **instructions, char *line)
{
	t_instruction	*tmp;
	t_instruction	*new;

	new = malloc(sizeof(t_instruction));
	if (!(new))
		return (1);
	new->line = ft_strdup(line);
	new->next = NULL;
	tmp = *instructions;
	while (tmp && tmp->next)
		tmp = tmp->next;
	if (tmp)
		tmp->next = new;
	else
		*instructions = new;
	return (0);
}
