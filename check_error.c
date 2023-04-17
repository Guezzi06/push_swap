/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguezzi <aguezzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:36:54 by aguezzi           #+#    #+#             */
/*   Updated: 2023/04/13 13:23:25 by aguezzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_doublon(t_tableau *tabs)
{
	int	i;
	int	j;
	int	*tab;

	i = 0;
	tab = malloc(sizeof(int) * (tabs->len_a));
	if (!tab)
		return (0);
	while (i < tabs->len_a)
	{
		tab[i] = (tabs->tab_a)[i];
		j = 0;
		while (j < i)
		{
			if (tab[j] == tab[i])
				return (0);
			j++;
		}
		i++;
	}
	free(tab);
	return (1);
}

int	check_numbers(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	if (argc == 1 && !ft_str_is_numeric(argv[0]))
		return (0);
	while (i < argc)
	{
		j = 0;
		if (argv[i][0] == '-' || argv[i][0] == '+')
			j++;
		if (argv[i][j] == '\0')
			return (0);
		while (argv[i][j])
		{
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

long	ft_atoi_pswap(char *n, t_tableau *tabs)
{
	int		i;
	int		sign;
	long	nbr;

	i = 0;
	sign = 1;
	nbr = 0;
	while (n[i] == ' ' || n[i] == '\n' || n[i] == '\f' || n[i] == '\v'
		|| n[i] == '\t' || n[i] == '\r')
		i++;
	if (n[i] == '-' || n[i] == '+')
	{
		if (n[i] == '-')
			sign *= -1;
		i++;
	}
	while (n[i] >= '0' && n[i] <= '9')
	{
		nbr = nbr * 10 + n[i] - 48;
		i++;
	}
	check_error_int(n, nbr * sign, tabs);
	return (nbr * sign);
}

void	check_error_int(char *n, long nbr, t_tableau *tabs)
{
	if (!(ft_strlen(n) <= 11 && nbr >= -2147483648 && nbr <= 2147483647))
	{
		ft_printf("Error\n");
		free_and_exit(tabs);
	}
}

void	free_and_exit(t_tableau *tabs)
{
	int	i;

	i = 0;
	free(tabs->tab_a);
	free(tabs->tab_b);
	if (tabs->split_numbers)
	{
		while ((tabs->split_numbers)[i])
		{
			free((tabs->split_numbers)[i]);
			i++;
		}
		free(tabs->split_numbers);
	}
	if (tabs->pile_sorted)
		free(tabs->pile_sorted);
	exit (0);
}
