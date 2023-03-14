/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 06:59:03 by mkarakul          #+#    #+#             */
/*   Updated: 2023/03/13 07:25:12 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_bzero(void *s, size_t n)
{
	char	*tmp;

	while (n--)
	{
		tmp = (char *)s;
		*tmp = 0;
		s++;
	}
}

int	get_instruction(t_instruction **instructions)
{
	int		ret;
	char	line[4];

	ft_bzero(line, 4);
	ret = read(STDIN_FILENO, line, 3);
	if (ret <= 0)
		return (ret);
	if (line[2] != '\n')
	{
		if (line[0] == '\n' || line[1] == '\n')
			return (-1);
		if (read(STDIN_FILENO, line + 3, 1) < 0 || line[3] != '\n')
			return (-1);
		line[3] = '\0';
	}
	else
		line[2] = '\0';
	return (get_instruction2(instructions, line));
}

int	get_instruction2(t_instruction **instructions, char *line)
{
	if (ft_strcmp(line, "sa") && ft_strcmp(line, "sb") && ft_strcmp(line, "ss")
		&& ft_strcmp(line, "pa") && ft_strcmp(line, "pb")
		&& ft_strcmp(line, "ra") && ft_strcmp(line, "rb")
		&& ft_strcmp(line, "rr") && ft_strcmp(line, "rra")
		&& ft_strcmp(line, "rrb") && ft_strcmp(line, "rrr"))
		return (-1);
	if (add_instruction(instructions, line))
		return (-1);
	return (1);
}
