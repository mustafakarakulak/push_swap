/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_process2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 16:58:19 by mkarakul          #+#    #+#             */
/*   Updated: 2023/03/05 19:40:16 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_get_movecount(int size, int index)
{
	if (index == size - 1)
		return (0);
	if (index >= size / 2)
		return ((size - 1) - index);
	return (-(index + 1));
}

void	ft_sortmove_a(t_data *data, int index_a, int index_b)
{
	if (index_b > 0)
	{
		if (index_a < index_b)
		{
			ft_sort_fnhook(ft_abs(index_a), &ft_rotate, data, 'x');
			ft_sort_fnhook(index_b - index_a, &ft_rotate, data, 'b');
		}
		else
		{
			ft_sort_fnhook(ft_abs(index_b), &ft_rotate, data, 'x');
			ft_sort_fnhook(index_a - index_b, &ft_rotate, data, 'a');
		}
	}
	else
	{
		ft_sort_fnhook(ft_abs(index_b), &ft_revrotate, data, 'b');
		ft_sort_fnhook(index_a, &ft_rotate, data, 'a');
	}
}

void	ft_sortmove_b(t_data *data, int index_a, int index_b)
{
	if (index_b < 0)
	{
		if (index_a < index_b)
		{
			ft_sort_fnhook(ft_abs(index_b), &ft_revrotate, data, 'x');
			ft_sort_fnhook(ft_abs(index_b - index_a),
				&ft_revrotate, data, 'a');
		}
		else
		{
			ft_sort_fnhook(ft_abs(index_a), &ft_revrotate, data, 'x');
			ft_sort_fnhook(ft_abs(index_a - index_b),
				&ft_revrotate, data, 'b');
		}
	}
	else
	{
		ft_sort_fnhook(index_b, &ft_rotate, data, 'b');
		ft_sort_fnhook(ft_abs(index_a), &ft_revrotate, data, 'a');
	}
}
