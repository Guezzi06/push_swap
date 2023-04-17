/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_instructions_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguezzi <aguezzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 13:41:01 by aguezzi           #+#    #+#             */
/*   Updated: 2023/04/12 15:33:10 by aguezzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_sb(int instruction, t_tableau *tabs)
{
	int	*ptr;
	int	save;
	int	i;

	i = 0;
	if (instruction == 1)
	{
		ptr = tabs->tab_a;
		ft_printf("sa\n");
	}
	else
	{
		ptr = tabs->tab_b;
		ft_printf("sb\n");
	}
	save = ptr[0];
	ptr[0] = ptr[1];
	ptr[1] = save;
}

void	pa(t_tableau *tabs)
{
	int	save;
	int	i;

	i = 0;
	save = (tabs->tab_b)[0];
	while (i < tabs->len_b - 1)
	{
		(tabs->tab_b)[i] = (tabs->tab_b)[i + 1];
		i++;
	}
	tabs->len_b --;
	tabs->len_a ++;
	i = tabs->len_a - 1;
	while (i > 0)
	{
		(tabs->tab_a)[i] = (tabs->tab_a)[i - 1];
		i--;
	}
	(tabs->tab_a)[0] = save;
	ft_printf("pa\n");
}

void	pb(t_tableau *tabs)
{
	int	save;
	int	i;

	i = 0;
	save = (tabs->tab_a)[0];
	while (i < tabs->len_a - 1)
	{
		(tabs->tab_a)[i] = (tabs->tab_a)[i + 1];
		i++;
	}
	tabs->len_a --;
	tabs->len_b ++;
	i = tabs->len_b - 1;
	while (i > 0)
	{
		(tabs->tab_b)[i] = (tabs->tab_b)[i - 1];
		i--;
	}
	(tabs->tab_b)[0] = save;
	ft_printf("pb\n");
}
