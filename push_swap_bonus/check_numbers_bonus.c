/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_numbers_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 15:59:29 by mkarakul          #+#    #+#             */
/*   Updated: 2023/03/12 17:23:57 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_check_numbers(int ac, char **av)
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
			ft_error("Error: Empty argument");
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
	while (str[i] && str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] && str[i] != ' ')
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (ft_error("Error"));
		*is_num = ++i;
	}
	if (!*is_num)
		return (ft_error("Error"));
	while (str[i] && str[i] == ' ')
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

int	ft_check_sorted(t_data *p)
{
	int	i;

	i = 0;
	if (p->b_size != 0)
		return (0);
	while (i < p->total_size - 1)
	{
		if (p->arr_a[i] > p->arr_a[i + 1])
			i++;
		else
			return (0);
	}
	return (1);
}
