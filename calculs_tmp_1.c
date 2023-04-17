/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculs_tmp_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguezzi <aguezzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:46:55 by aguezzi           #+#    #+#             */
/*   Updated: 2023/04/12 15:33:06 by aguezzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calcul_min_max(t_tableau *tabs)
{
	int	i;

	i = 0;
	while (i < tabs->len_a)
	{
		if ((tabs->max_pile) < (tabs->tab_a)[i])
			(tabs->max_pile) = (tabs->tab_a)[i];
		if ((tabs->min_pile) > (tabs->tab_a)[i])
			(tabs->min_pile) = (tabs->tab_a)[i];
		i++;
	}
}

void	min_max_tmp(t_tableau *tabs)
{
	min_max_a_tmp(tabs);
	min_max_b_tmp(tabs);
}

void	min_max_a_tmp(t_tableau *tabs)
{
	int	i;

	i = 0;
	tabs->max_a_tmp = (tabs->tab_a)[0];
	tabs->min_a_tmp = (tabs->tab_a)[0];
	tabs->index_max_a_tmp = 0;
	tabs->index_min_a_tmp = 0;
	while (i < tabs->len_a)
	{
		if ((tabs->max_a_tmp) < (tabs->tab_a)[i])
		{
			(tabs->max_a_tmp) = (tabs->tab_a)[i];
			tabs->index_max_a_tmp = i;
		}
		if ((tabs->min_a_tmp) > (tabs->tab_a)[i])
		{
			(tabs->min_a_tmp) = (tabs->tab_a)[i];
			tabs->index_min_a_tmp = i;
		}
		i++;
	}
}

void	min_max_b_tmp(t_tableau *tabs)
{
	int	i;

	i = 0;
	tabs->max_b_tmp = (tabs->tab_b)[0];
	tabs->min_b_tmp = (tabs->tab_b)[0];
	tabs->index_max_b_tmp = 0;
	tabs->index_min_b_tmp = 0;
	while (i < tabs->len_b)
	{
		if ((tabs->max_b_tmp) < (tabs->tab_b)[i])
		{
			(tabs->max_b_tmp) = (tabs->tab_b)[i];
			tabs->index_max_b_tmp = i;
		}
		if ((tabs->min_b_tmp) > (tabs->tab_b)[i])
		{
			(tabs->min_b_tmp) = (tabs->tab_b)[i];
			tabs->index_min_b_tmp = i;
		}
		i++;
	}
}
