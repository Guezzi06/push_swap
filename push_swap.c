/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguezzi <aguezzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 11:27:07 by aguezzi           #+#    #+#             */
/*   Updated: 2023/04/12 15:33:02 by aguezzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_tableau	tabs;

	if (argc >= 2)
	{
		init_ptr(&tabs);
		create_piles(argc, argv, &tabs);
		if (!pile_is_sorted(&tabs))
		{
			init_tableau(&tabs);
			copy(&tabs);
			sorted_list(&tabs);
			if (tabs.len_a >= 2)
				choose_algo(tabs.len_a, tabs.tab_a, &tabs);
		}
		free_and_exit(&tabs);
	}
	return (0);
}

void	choose_algo(int numbers, int *tab, t_tableau *tabs)
{
	if (numbers == 2)
		algo_2numbers(tab, tabs);
	else if (numbers == 3)
		algo_3numbers(tab, tabs);
	else if (numbers == 4)
		algo_4numbers(tab, tabs);
	else if (numbers == 5)
		algo_5numbers(tab, tabs);
	else if (numbers <= 10)
		algo_10numbers(tab, tabs);
	else
		algo_big_numbers(tabs);
}

int	pile_is_sorted(t_tableau *tabs)
{
	int	i;

	i = 0;
	while (i < tabs->len_a - 1)
	{
		if ((tabs->tab_a)[i] > (tabs->tab_a)[i + 1])
			return (0);
		i++;
	}
	return (1);
}
