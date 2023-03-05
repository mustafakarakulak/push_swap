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

int	ft_init(t_data *p)
{
	p->stack_a = malloc(sizeof(int) * p->total_size);
	if (!p->stack_a)
		return (ft_error("Error: Allocation error A"));
	p->stack_b = malloc(sizeof(int) * p->total_size);
	if (!p->stack_b)
		return (ft_error("Error: Allocation error B"));
	p->a_size = 0;
	p->b_size = 0;
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
		result = result * 10 + (*str - '0');
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
	ft_putstr(s);
	ft_putstr("\n");
	exit(1);
	return (0);
}
