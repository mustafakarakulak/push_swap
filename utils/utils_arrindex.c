/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_arrindex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 16:58:32 by mkarakul          #+#    #+#             */
/*   Updated: 2023/03/06 18:46:02 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_array_numidx(t_data *data)
{
	int	i;
	int	int_min;
	int	minindex;
	int	*temp;

	i = 0;
	int_min = INT_MIN;
	temp = malloc(sizeof(int) * data->total_size);
	while (i < data->a_size)
	{
		minindex = ft_array_minidx(data->stack_a, data->a_size, int_min);
		int_min = data->stack_a[minindex];
		temp[minindex] = i;
		i++;
	}
	free(data->stack_a);
	data->stack_a = temp;
}

int	ft_array_minidx(int *arr, unsigned long size, int start)
{
	unsigned long	i;
	int				second;

	i = -1;
	while (++i < size)
		if (arr[i] > start)
			second = i;
	i = -1;
	while (++i < size)
	{
		if (arr[i] > start && arr[i] < arr[second])
			second = i;
	}
	return (second);
}
