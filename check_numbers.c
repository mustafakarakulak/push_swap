/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 16:58:00 by mkarakul          #+#    #+#             */
/*   Updated: 2023/03/05 21:39:18 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_numbers(int ac, char **av)
{
	int	i;
	int	j;
	int	is_num;
	int	c_total;

	i = 1;
	c_total = 0;
	while (i < ac)
	{
		if (!ft_strlen(av[i]))
			ft_error("Error:");
		j = 0;
		while (av[i][j])
		{
			is_num = 0;
			j += ft_check_number(&av[i][j], &is_num);
			if (is_num)
				c_total++;
		}
		i++;
	}
	return (c_total);
}

int	ft_check_number(char *str, int *is_num)
{
	int	i;

	i = 0;
	while (str[i] && str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] && str[i] != 32)
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (ft_error("Error: Geçersiz argüman var!"));
		i++;
	}
	*is_num = i;
	while (str[i] && str[i] == 32)
		i++;
	return (i);
}

int	check_samenum(int *arr, int n, int index, int size)
{
	while (index < size)
	{
		if (arr[index] == n)
		{
			return (1);
		}
		index++;
	}
	return (0);
}

int	check_stack(t_data *p)
{
	int	i;

	i = 0;
	while (i < p->a_size - 1)
	{
		if (p->stack_a[i] > p->stack_a[i + 1])
			i++;
		else
			return (0);
	}
	return (1);
}

int	check_sorted(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->a_size - 1)
	{
		if (data->stack_a[i] > data->stack_a[i + 1])
			i++;
		else
			return (0);
	}
	ft_putstr("Sıralı argüman dizisi gönderdiniz\n");
	return (1);
}
