/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_generic.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 16:58:35 by mkarakul          #+#    #+#             */
/*   Updated: 2023/03/04 16:58:35 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_init(t_data *data)
{
	data->stack_a = malloc(sizeof(int) * data->total_size);
	if (!data->stack_a)
		return (ft_error("Error"));
	data->stack_b = malloc(sizeof(int) * data->total_size);
	if (!data->stack_b)
		return (ft_error("Error"));
	data->a_size = 0;
	data->b_size = 0;
	return (1);
}

int	ft_atoi(char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign = -1;
	while (*str && *str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - 48);
		if (result * sign > INT_MAX)
			return (ft_error("Error"));
		if (result * sign < INT_MIN)
			return (ft_error("Error"));
		str++;
	}
	return ((int)result * sign);
}

int	ft_abs(int nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

int	ft_error(char *s)
{
	(void)s;
	write(2, "Error\n", 6);
	exit(1);
	return (0);
}
