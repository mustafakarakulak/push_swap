/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 16:58:09 by mkarakul          #+#    #+#             */
/*   Updated: 2023/03/12 16:02:41 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_data
{
	int	*stack_a;
	int	*stack_b;
	int	a_size;
	int	b_size;
	int	total_size;
}	t_data;

int		check_numbers(int ac, char **av);
int		check_samenum(int *arr, int n, int index, int size);
int		ft_check_number(char *str, int *is_num);
int		check_stack(t_data *data);
int		check_sorted(t_data *data);

void	ft_array_numidx(t_data *p);
int		ft_array_minidx(int *arr, size_t size, int start);
int		ft_array_pivot(int *arr, int size);

void	ft_array_push(int *arr, int size, int value);
void	ft_array_swap(int *arr, int size);
void	ft_array_rotate(int *arr, int size);
void	ft_array_revrotate(int *arr, int size);

void	ft_push(t_data *data, char check);
void	ft_swap(t_data *data, char check);
void	ft_rotate(t_data *data, char check);
void	ft_revrotate(t_data *data, char check);

void	ft_sort_pivot(t_data *data);
void	ft_sort_underfive(t_data *p_data);
int		ft_array_pivot(int *arr, int size);

int		ft_sort_process(t_data *data);
int		ft_sort_move(t_data *data, int index_a, int index_b);
void	ft_sort_move2(t_data *data, int side);
void	ft_sortmove_a(t_data *data, int index_a, int index_b);
void	ft_sortmove_b(t_data *data, int index_a, int index_b);
void	ft_sort_fnhook(int count, void (*fn)(t_data *, char),
			t_data *p, char check);

int		ft_get_totalmove(t_data *data, int index, int *index_a);
int		ft_get_movecount(int size, int index);

void	ft_numprocess(t_data *s, int ac, char **av);
void	ft_putnumber(t_data *s, char *str);

int		ft_init(t_data *data);
int		ft_atoi(char *str);
int		ft_abs(int nb);
int		ft_error(char *s);

size_t	ft_strlen(char *str);
int		ft_putstr(char *str);

#endif