/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimisation_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguezzi <aguezzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 12:50:45 by aguezzi           #+#    #+#             */
/*   Updated: 2023/04/12 15:33:21 by aguezzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	optimisation(int ref, t_tableau *tabs)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	min_max_tmp(tabs);
	if (tabs->len_b >= 2)
		opti_first_if(i, j, ref, tabs);
	else
	{
		while ((tabs->tab_a)[0] > (tabs->pile_sorted)[ref])
			ra_rb(1, tabs);
	}
	if ((tabs->tab_a)[0] <= (tabs->pile_sorted)[ref])
		pb(tabs);
}

void	opti_first_if(int i, int j, int ref, t_tableau *tabs)
{
	while ((tabs->tab_a)[i] > (tabs->pile_sorted)[ref])
		i++;
	if ((tabs->tab_a)[i] > tabs->max_b_tmp)
	{
		while ((tabs->tab_b)[j] != tabs->max_b_tmp)
			j++;
		opti_first_part(i, j, ref, tabs);
	}
	else
	{
		if ((tabs->tab_a)[i] < tabs->min_b_tmp)
			opti_second_part(i, j, ref, tabs);
		else
			opti_third_part(i, j, ref, tabs);
	}
}

void	opti_first_part(int i, int j, int ref, t_tableau *tabs)
{
	if (j <= i)
	{
		while ((tabs->tab_b)[0] != tabs->max_b_tmp)
			rr(tabs);
		while ((tabs->tab_a)[0] > (tabs->pile_sorted)[ref])
			ra_rb(1, tabs);
	}
	else
	{
		if (j - i <= tabs->len_b - j)
		{
			while ((tabs->tab_a)[0] > (tabs->pile_sorted)[ref])
				rr(tabs);
			while ((tabs->tab_b)[0] != tabs->max_b_tmp)
				ra_rb(2, tabs);
		}
		else
		{
			while ((tabs->tab_a)[0] > (tabs->pile_sorted)[ref])
				ra_rb(1, tabs);
			while ((tabs->tab_b)[0] != tabs->max_b_tmp)
				rra_rrb(2, tabs);
		}
	}
}

void	opti_second_part(int i, int j, int ref, t_tableau *tabs)
{
	if ((tabs->tab_a)[i] < tabs->min_b_tmp)
	{
		while ((tabs->tab_b)[j] != tabs->min_b_tmp)
			j++;
		if (j + 1 <= i)
		{
			while ((tabs->tab_b)[0] != tabs->max_b_tmp)
				rr(tabs);
			while ((tabs->tab_a)[0] > (tabs->pile_sorted)[ref])
				ra_rb(1, tabs);
		}
		else
			else_second_part(i, j, ref, tabs);
	}
}

void	else_second_part(int i, int j, int ref, t_tableau *tabs)
{
	if (j + 1 - i <= tabs->len_b - j - 1)
	{
		while ((tabs->tab_a)[0] > (tabs->pile_sorted)[ref])
			rr(tabs);
		while ((tabs->tab_b)[tabs->len_b - 1] != tabs->min_b_tmp)
			ra_rb(2, tabs);
	}
	else
	{
		while ((tabs->tab_a)[0] > (tabs->pile_sorted)[ref])
			ra_rb(1, tabs);
		while ((tabs->tab_b)[tabs->len_b - 1] != tabs->min_b_tmp)
			rra_rrb(2, tabs);
	}
}
