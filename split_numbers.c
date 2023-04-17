/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguezzi <aguezzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 10:35:00 by aguezzi           #+#    #+#             */
/*   Updated: 2023/04/12 15:33:24 by aguezzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	split_numbers(char **argv, t_tableau *tabs)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (argv[1][i])
	{
		while (argv[1][i] == ' ')
			i++;
		if (argv[1][i] == '\0')
			break ;
		while (argv[1][i] != ' ' && argv[1][i])
			i++;
		count++;
	}
	tabs->split_numbers = ft_split(argv[1], ' ');
	split_create(count, tabs);
	check_errors_split(count, tabs);
}

void	split_create(int count, t_tableau *tabs)
{
	int	i;

	i = 0;
	tabs->tab_a = malloc(sizeof(int) * (count));
	tabs->tab_b = malloc(sizeof(int) * (count));
	if (tabs->tab_a == NULL || tabs->tab_b == NULL)
		exit (0);
	while ((tabs->split_numbers)[i])
	{
		(tabs->tab_a)[i] = ft_atoi_pswap((tabs->split_numbers)[i], tabs);
		tabs->len_a ++;
		i++;
	}
}

void	check_errors_split(int count, t_tableau *tabs)
{
	if (tabs->len_a == 0)
		exit (0);
	if (!check_numbers(count, tabs->split_numbers))
	{
		ft_printf("Error\n");
		free_and_exit(tabs);
	}
	if (!check_doublon(tabs))
	{
		ft_printf("Error\n");
		free_and_exit(tabs);
	}
}
