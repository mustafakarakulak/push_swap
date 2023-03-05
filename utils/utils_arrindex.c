/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_arrindex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 16:58:32 by mkarakul          #+#    #+#             */
/*   Updated: 2023/03/05 20:52:45 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_array_numidx(t_data *data)
{
	int	i;
	int	min;
	int	minindex;
	int	*temp;

	temp = malloc(sizeof(int) * data->total_size);
	i = -1;
	min = INT_MIN;
	while (++i < data->a_size)
	{
		minindex = ft_array_minidx(data->stack_a, data->a_size, min);
		min = data->stack_a[minindex];
		temp[minindex] = i;
	}
	free(data->stack_a);
	data->stack_a = temp;
}

int	ft_array_minidx(int *arr, size_t size, int start)
{
	size_t	i;
	int		second;

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
