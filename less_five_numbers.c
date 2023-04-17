/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   less_five_numbers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguezzi <aguezzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 12:31:44 by aguezzi           #+#    #+#             */
/*   Updated: 2023/04/12 15:33:15 by aguezzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo_2numbers(int *tab, t_tableau *tabs)
{
	if (tab[0] > tab[1])
		sa_sb(1, tabs);
}

void	algo_3numbers(int *tab, t_tableau *tabs)
{
	if (tab[0] > tab[1] && tab[1] > tab[2])
	{
		sa_sb(1, tabs);
		rra_rrb(1, tabs);
	}
	else if (tab[0] > tab[1] && tab[1] < tab[2] && tab[0] > tab[2])
		ra_rb(1, tabs);
	else if (tab[0] < tab[1] && tab[1] > tab[2] && tab[0] > tab[2])
		rra_rrb(1, tabs);
	else if (tab[0] > tab[1] && tab[1] < tab[2] && tab[0] < tab[2])
		sa_sb(1, tabs);
	else if (tab[0] < tab[1] && tab[1] > tab[2] && tab[0] < tab[2])
	{
		sa_sb(1, tabs);
		ra_rb(1, tabs);
	}
}

void	algo_4numbers(int *tab, t_tableau *tabs)
{
	int	i;

	i = 0;
	min_max_tmp(tabs);
	if (tabs->index_min_a_tmp > tabs->len_a / 2)
	{
		while ((tabs->tab_a)[0] != tabs->min_a_tmp)
			rra_rrb(1, tabs);
	}
	else
	{
		while ((tabs->tab_a)[0] != tabs->min_a_tmp)
			ra_rb(1, tabs);
	}
	pb(tabs);
	algo_3numbers(tab, tabs);
	pa(tabs);
}

void	algo_5numbers(int *tab, t_tableau *tabs)
{
	int	i;

	i = 0;
	min_max_tmp(tabs);
	if (tabs->index_min_a_tmp > tabs->len_a / 2)
	{
		while ((tabs->tab_a)[0] != tabs->min_a_tmp)
			rra_rrb(1, tabs);
	}
	else
	{
		while ((tabs->tab_a)[0] != tabs->min_a_tmp)
			ra_rb(1, tabs);
	}
	pb(tabs);
	algo_4numbers(tab, tabs);
	pa(tabs);
}
