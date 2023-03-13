/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 16:02:50 by mkarakul          #+#    #+#             */
/*   Updated: 2023/03/12 19:02:08 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_data
{
	int	*arr_a;
	int	*arr_b;
	int	a_size;
	int	b_size;
	int	total_size;
}	t_data;

int		ft_strlen(char *str);
int		intjoin(int **arr, int number, int *size);
int		ft_putstr(char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_check_numbers(int ac, char **av);
int		ft_atoi(char *str);
int		rule_check(char *str, int **steps, int *size, int i);
int		ft_error(char *s);
int		check_samenum(int *arr, int n, int index, int size);
int		ft_check_number(char *str, int *is_num);
int		ft_check_sorted(t_data *p);
int		ft_init(t_data *p);

void	ft_swap(t_data *p, char check);
void	ft_rotate(t_data *p, char check);
void	ft_array_revrotate(int *arr, int size);
void	ft_push(t_data *p, char check);
void	ft_array_rotate(int *arr, int size);
void	ft_array_swap(int *arr, int size);
void	ft_array_push(int *arr, int size, int value);
void	ft_read(int **steps, int *size);
void	ft_revrotate(t_data *p, char check);
void	try_steps(t_data *p, int *steps, int size, int i);
void	ft_numprocess(t_data *p, int ac, char **av);
void	ft_putnumber(t_data *p, char *str);
void	*ft_calloc(size_t nitems, size_t size);

#endif