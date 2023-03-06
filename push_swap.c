/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 16:58:06 by mkarakul          #+#    #+#             */
/*   Updated: 2023/03/06 17:41:04 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_threearg(t_data *data)
{
	if (data->a_size == 3)
	{
		if (ft_array_minidx(data->stack_a, data->a_size, INT_MIN) == 0)
		{
			if (data->stack_a[1] > data->stack_a[2])
				ft_sort_fnhook(1, &ft_revrotate, data, 'a');
			else if (data->stack_a[1] < data->stack_a[2])
				ft_sort_fnhook(1, &ft_rotate, data, 'a');
		}
		else if (ft_array_minidx(data->stack_a, data->a_size, INT_MIN) == 1)
		{
			if (data->stack_a[0] > data->stack_a[2])
				ft_swap(data, 'a');
			else if (data->stack_a[0] < data->stack_a[2])
				ft_sort_fnhook(1, &ft_rotate, data, 'a');
		}
		else if (ft_array_minidx(data->stack_a, data->a_size,
				INT_MIN) == 2 && data->stack_a[1] > data->stack_a[0])
		{
			ft_swap(data, 'a');
			ft_sort_fnhook(1, &ft_rotate, data, 'a');
		}
	}
}

void	ft_sort_fivearg(t_data *data)
{
	int	min;
	int	i;
	int	side;

	min = INT_MIN;
	while (data->a_size > 3)
	{
		i = ft_array_minidx(data->stack_a, data->a_size, min);
		min = data->stack_a[i];
		side = ft_get_movecount(data->a_size, i);
		ft_sort_move2(data, side);
	}
	ft_sort_threearg(data);
	if (!check_stack(data))
		ft_swap(data, 'a');
	ft_sort_fnhook(data->b_size, &ft_push, data, 'a');
}

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac > 1)
	{
		data = malloc(sizeof(t_data));
		if (ac == 2)
			return (0);
		data->total_size = check_numbers(ac, av);
		ft_numprocess(data, ac, av);
		if (check_sorted(data) == 1)
			return (0);
		ft_array_numidx(data);
		if (data->total_size > 5)
		{
			ft_sort_pivot(data);
			ft_sort_process(data);
		}
		else
			ft_sort_fivearg(data);
		while (!check_stack(data))
			ft_rotate(data, 'a');
	}
	else
		ft_error("Hatalı kullanım.");
}
