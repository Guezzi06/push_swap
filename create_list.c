/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguezzi <aguezzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 12:06:49 by aguezzi           #+#    #+#             */
/*   Updated: 2023/04/12 15:33:04 by aguezzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_piles(int argc, char **argv, t_tableau *tabs)
{
	int	i;

	i = 0;
	tabs->len_a = 0;
	tabs->len_b = 0;
	if (argc == 2)
		split_numbers(argv, tabs);
	else
	{
		tabs->tab_a = malloc(sizeof(int) * (argc - 1));
		tabs->tab_b = malloc(sizeof(int) * (argc - 1));
		if (tabs->tab_a == NULL || tabs->tab_b == NULL)
			free_and_exit(tabs);
		while (i < argc - 1)
		{
			(tabs->tab_a)[i] = ft_atoi_pswap(argv[i + 1], tabs);
			tabs->len_a ++;
			i++;
		}
		if (!(check_numbers(argc, argv) && check_doublon(tabs)))
		{
			ft_printf("Error\n");
			free_and_exit(tabs);
		}
	}
}

void	init_tableau(t_tableau *tabs)
{
	tabs->max_pile = (tabs->tab_a)[0];
	tabs->min_pile = (tabs->tab_a)[0];
	tabs->total = tabs->len_a;
	tabs->mediane = 0;
	calcul_min_max(tabs);
}

void	init_ptr(t_tableau *tabs)
{
	tabs->pile_sorted = NULL;
	tabs->split_numbers = NULL;
}

void	copy(t_tableau *tabs)
{
	int	i;

	i = 0;
	tabs->pile_sorted = malloc(sizeof(int) * (tabs->len_a));
	if (tabs->pile_sorted == NULL)
		free_and_exit(tabs);
	while (i < tabs->len_a)
	{
		(tabs->pile_sorted)[i] = (tabs->tab_a)[i];
		i++;
	}
}

void	sorted_list(t_tableau *tabs)
{
	int	i;
	int	j;
	int	save;

	j = 0;
	while (j < tabs->len_a - 1)
	{
		i = 0;
		while (i < tabs->len_a - 1)
		{
			if ((tabs->pile_sorted)[i] > (tabs->pile_sorted)[i + 1])
			{
				save = (tabs->pile_sorted)[i];
				(tabs->pile_sorted)[i] = (tabs->pile_sorted)[i + 1];
				(tabs->pile_sorted)[i + 1] = save;
			}
			i++;
		}
		j++;
	}
	if (tabs->len_a % 2 == 0)
		tabs->mediane = (tabs->pile_sorted)[tabs->len_a / 2];
	else
		tabs->mediane = (tabs->pile_sorted)[tabs->len_a / 2 + 1];
}
