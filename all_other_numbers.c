/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_other_numbers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguezzi <aguezzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 12:33:36 by aguezzi           #+#    #+#             */
/*   Updated: 2023/04/12 15:33:17 by aguezzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo_10numbers(int *tab, t_tableau *tabs)
{
	while (tabs->len_b < tabs->total / 2 + tabs->total % 2)
	{
		if ((tabs->tab_a)[0] < tabs->mediane)
			pb(tabs);
		else
			ra_rb(1, tabs);
	}
	if (tabs->total == 6)
	{
		algo_3numbers(tab, tabs);
		algo_3_b(tabs->tab_b, tabs);
	}
	else if (tabs->total == 7)
	{
		algo_3numbers(tab, tabs);
		algo_4_b(tabs->tab_b, tabs);
	}
	else
		suite_algo10(tab, tabs);
	while (tabs->len_b != 0)
		pa(tabs);
}

void	suite_algo10(int *tab, t_tableau *tabs)
{
	if (tabs->total == 8)
	{
		algo_4numbers(tab, tabs);
		algo_4_b(tabs->tab_b, tabs);
	}
	else if (tabs->total == 9)
	{
		algo_4numbers(tab, tabs);
		algo_5_b(tabs->tab_b, tabs);
	}
	else if (tabs->total == 10)
	{
		algo_5numbers(tab, tabs);
		algo_5_b(tabs->tab_b, tabs);
	}
}

void	algo_big_numbers(t_tableau *tabs)
{
	int	ref;
	int	div;

	if (tabs->total <= 100)
		div = 6;
	else
		div = 13;
	ref = tabs->total / div;
	while (tabs->len_a != 0)
	{
		optimisation(ref, tabs);
		if (tabs->len_b == ref + 1)
		{
			if (ref + tabs->total / div > tabs->total - 1)
				ref = tabs->total - 1;
			else
				ref += tabs->total / div;
		}
	}
	suite_algo_big(tabs);
}

void	suite_algo_big(t_tableau *tabs)
{
	while (tabs->len_b != 0)
	{
		min_max_tmp(tabs);
		while ((tabs->tab_b)[0] != tabs->max_b_tmp)
		{
			if (tabs->index_max_b_tmp <= tabs->len_b / 2)
				ra_rb(2, tabs);
			else
				rra_rrb(2, tabs);
		}
		pa(tabs);
	}
}
