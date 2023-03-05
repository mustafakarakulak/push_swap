/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_pivot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 16:58:14 by mkarakul          #+#    #+#             */
/*   Updated: 2023/03/04 16:58:14 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sort_pivot(t_data *data)
{
	int	res;

	while (data->a_size > 2)
	{
		res = ft_array_pivot(data->stack_a, data->a_size);
		if (data->stack_a[data->a_size - 1] < res)
			ft_push(data, 'b');
		else
			ft_rotate(data, 'a');
	}
}

int	ft_array_pivot(int *arr, int size)
{
	unsigned long long	sum;
	int					i;

	i = 0;
	sum = 0;
	while (i < size)
		sum += arr[i++];
	return (sum / size);
}
