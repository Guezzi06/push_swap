/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimisation_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguezzi <aguezzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 12:52:06 by aguezzi           #+#    #+#             */
/*   Updated: 2023/04/12 15:33:23 by aguezzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	opti_third_part(int i, int j, int ref, t_tableau *tabs)
{
	if (!((tabs->tab_b)[0] < (tabs->tab_a)[i] &&
				(tabs->tab_b)[tabs->len_b - 1] > (tabs->tab_a)[i]))
	{
		j++;
		while (!((tabs->tab_b)[j - 1] > (tabs->tab_a)[i] &&
					(tabs->tab_b)[j] < (tabs->tab_a)[i]))
			j++;
	}
	if (j <= i)
	{
		while (j > 0)
		{
			rr(tabs);
			j--;
		}
		while ((tabs->tab_a)[0] > (tabs->pile_sorted)[ref])
			ra_rb(1, tabs);
	}
	else
		else_third_part(i, j, ref, tabs);
}

void	else_third_part(int i, int j, int ref, t_tableau *tabs)
{
	if (j - i <= tabs->len_b - j)
	{
		while ((tabs->tab_a)[0] > (tabs->pile_sorted)[ref])
			rr(tabs);
		while (!((tabs->tab_b)[0] < (tabs->tab_a)[0] &&
					(tabs->tab_b)[tabs->len_b - 1] > (tabs->tab_a)[0]))
			ra_rb(2, tabs);
	}
	else
	{
		while ((tabs->tab_a)[0] > (tabs->pile_sorted)[ref])
			ra_rb(1, tabs);
		while (!((tabs->tab_b)[0] < (tabs->tab_a)[0] &&
					(tabs->tab_b)[tabs->len_b - 1] > (tabs->tab_a)[0]))
			rra_rrb(2, tabs);
	}
}
