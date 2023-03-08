/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 16:58:16 by mkarakul          #+#    #+#             */
/*   Updated: 2023/03/08 18:52:26 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_sort_process(t_data *data)
{
	int	i;
	int	idx_a;
	int	idx_b;
	int	tmpidx_a;
	int	count;

	while (data->b_size)
	{
		i = 0;
		count = INT_MAX;
		while (i < data->b_size)
		{
			if (count > ft_get_totalmove(data, i, &tmpidx_a))
			{
				count = ft_get_totalmove(data, i, &tmpidx_a);
				idx_a = tmpidx_a;
				idx_b = i;
			}
			i++;
		}
		ft_sort_move(data, ft_get_movecount(data->a_size, idx_a),
			ft_get_movecount(data->b_size, idx_b));
	}
	return (1);
}

void	ft_sort_fnhook(int count, void (*fn)(t_data*, char),
		t_data *data, char check)
{
	int	i;

	i = 0;
	while (i < count)
	{
		fn(data, check);
		i++;
	}
}

int	ft_sort_move(t_data *data, int index_a, int index_b)
{
	if (index_a > 0)
		ft_sortmove_a(data, index_a, index_b);
	else
		ft_sortmove_b(data, index_a, index_b);
	ft_push(data, 'a');
	return (1);
}

void	ft_sort_move2(t_data *data, int side)
{
	if (side > 0)
		ft_sort_fnhook(side, &ft_rotate, data, 'a');
	if (side < 0)
		ft_sort_fnhook(ft_abs(side), &ft_revrotate, data, 'a');
	ft_push(data, 'b');
}

int	ft_get_totalmove(t_data *data, int index, int *index_a)
{
	int	count;

	*index_a = ft_array_minidx(data->stack_a, data->a_size,
			data->stack_b[index]);
	count = ft_abs(ft_get_movecount(data->b_size, index));
	if (*index_a == -1)
		return (ft_error("Error"));
	count += ft_abs(ft_get_movecount(data->a_size, *index_a));
	return (count);
}
