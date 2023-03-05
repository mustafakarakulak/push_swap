/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pushswap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 16:58:38 by mkarakul          #+#    #+#             */
/*   Updated: 2023/03/05 19:38:03 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_push(t_data *data, char check)
{
	if (check == 'a')
	{
		ft_array_push(data->stack_a, data->a_size++,
			data->stack_b[data->b_size-- - 1]);
		ft_putstr("pa\n");
	}
	else
	{
		ft_array_push(data->stack_b, data->b_size++,
			data->stack_a[data->a_size-- - 1]);
		ft_putstr("pb\n");
	}
}

void	ft_swap(t_data *data, char check)
{
	if (check == 'a')
	{
		ft_array_swap(data->stack_a, data->a_size);
		ft_putstr("sa\n");
	}
	else if (check == 'b')
	{
		ft_array_swap(data->stack_b, data->b_size);
		ft_putstr("sb\n");
	}
	else if (check == 'x')
	{
		ft_array_swap(data->stack_a, data->a_size);
		ft_array_swap(data->stack_b, data->b_size);
		ft_putstr("ss\n");
	}
}

void	ft_rotate(t_data *data, char check)
{
	if (check == 'a')
	{
		ft_array_rotate(data->stack_a, data->a_size);
		ft_putstr("ra\n");
	}
	else if (check == 'b')
	{
		ft_array_rotate(data->stack_b, data->b_size);
		ft_putstr("rb\n");
	}
	else if (check == 'x')
	{
		ft_array_rotate(data->stack_a, data->a_size);
		ft_array_rotate(data->stack_b, data->b_size);
		ft_putstr("rr\n");
	}
}

void	ft_revrotate(t_data *data, char check)
{
	if (check == 'a')
	{
		ft_array_revrotate(data->stack_a, data->a_size);
		ft_putstr("rra\n");
	}
	else if (check == 'b')
	{
		ft_array_revrotate(data->stack_b, data->b_size);
		ft_putstr("rrb\n");
	}
	else if (check == 'x')
	{
		ft_array_revrotate(data->stack_a, data->a_size);
		ft_array_revrotate(data->stack_b, data->b_size);
		ft_putstr("rrr\n");
	}
}
