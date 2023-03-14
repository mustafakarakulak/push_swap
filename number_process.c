/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 16:58:03 by mkarakul          #+#    #+#             */
/*   Updated: 2023/03/08 01:46:19 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_numprocess(t_data *data, int ac, char **av)
{
	int	i;
	int	j;
	int	nm_start;

	ft_init(data);
	i = 0;
	while (++i < ac)
	{
		j = 0;
		nm_start = 0;
		while (av[i][j])
		{
			while (av[i][j] && av[i][j] == 32)
				j++;
			nm_start = j;
			if (av[i][j] == '+' || av[i][j] == '-')
				j++;
			while (av[i][j] && av[i][j] != 32)
				j++;
			ft_putnumber(data, &av[i][nm_start]);
			while (av[i][j] && av[i][j] == 32)
				j++;
		}
	}
}

void	ft_putnumber(t_data *data, char *str)
{
	int	number;

	number = ft_atoi(str);
	if (check_samenum(data->stack_a, number,
			data->total_size - data->a_size, data->total_size) == 1)
		ft_error("Error");
	ft_array_push(data->stack_a, (data->total_size - 1)
		- data->a_size++, number);
}
