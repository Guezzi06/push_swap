/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguezzi <aguezzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 09:40:58 by aguezzi           #+#    #+#             */
/*   Updated: 2023/04/12 15:33:12 by aguezzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo_2_b(int *tab, t_tableau *tabs)
{
	if (tab[0] < tab[1])
		sa_sb(2, tabs);
}

void	algo_3_b(int *tab, t_tableau *tabs)
{
	if (tab[0] < tab[1] && tab[1] < tab[2])
	{
		sa_sb(2, tabs);
		rra_rrb(2, tabs);
	}
	else if (tab[0] > tab[1] && tab[1] < tab[2] && tab[0] > tab[2])
	{
		sa_sb(2, tabs);
		ra_rb(2, tabs);
	}
	else if (tab[0] < tab[1] && tab[1] > tab[2] && tab[0] > tab[2])
		sa_sb(2, tabs);
	else if (tab[0] > tab[1] && tab[1] < tab[2] && tab[0] < tab[2])
		rra_rrb(2, tabs);
	else if (tab[0] < tab[1] && tab[1] > tab[2] && tab[0] < tab[2])
		ra_rb(2, tabs);
}

void	algo_4_b(int *tab, t_tableau *tabs)
{
	int	save;
	int	*b_sorted;

	save = (tabs->tab_b)[0];
	b_sorted = calcul_mediane_b(tabs);
	if (b_sorted == NULL)
		free_and_exit(tabs);
	pa(tabs);
	algo_3_b(tab, tabs);
	if (save < tabs->mediane_b_tmp && save > (tabs->tab_b)[tabs->len_b - 1])
	{
		while (tabs->tab_b[0] > save)
			rra_rrb(2, tabs);
	}
	else if (save >= tabs->mediane_b_tmp && save < (tabs->tab_b)[0])
	{
		while (tabs->tab_b[0] > save)
			ra_rb(2, tabs);
	}
	pb(tabs);
	while (tabs->tab_b[0] != b_sorted[0])
		ra_rb(2, tabs);
	free(b_sorted);
}

void	algo_5_b(int *tab, t_tableau *tabs)
{
	int	save;
	int	*b_sorted;

	save = (tabs->tab_b)[0];
	b_sorted = calcul_mediane_b(tabs);
	if (b_sorted == NULL)
		free_and_exit(tabs);
	pa(tabs);
	algo_4_b(tab, tabs);
	if (save < tabs->mediane_b_tmp && save > (tabs->tab_b)[tabs->len_b - 1])
	{
		while (tabs->tab_b[0] > save)
			rra_rrb(2, tabs);
	}
	else if (save >= tabs->mediane_b_tmp && save < (tabs->tab_b)[0])
	{
		while (tabs->tab_b[0] > save)
			ra_rb(2, tabs);
	}
	pb(tabs);
	while (tabs->tab_b[0] != b_sorted[0])
		ra_rb(2, tabs);
	free(b_sorted);
}
