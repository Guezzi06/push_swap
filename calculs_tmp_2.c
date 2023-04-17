/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculs_tmp_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguezzi <aguezzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 12:55:10 by aguezzi           #+#    #+#             */
/*   Updated: 2023/04/12 15:33:14 by aguezzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	b_sorted(int *copy, t_tableau *tabs)
{
	int	i;
	int	j;
	int	save;

	j = 0;
	while (j < tabs->len_b - 1)
	{
		i = 0;
		while (i < tabs->len_b - 1)
		{
			if (copy[i] < copy[i + 1])
			{
				save = copy[i];
				copy[i] = copy[i + 1];
				copy[i + 1] = save;
			}
			i++;
		}
		j++;
	}
}

int	*calcul_mediane_b(t_tableau *tabs)
{
	int	i;
	int	*copy_b;

	i = 0;
	copy_b = malloc(sizeof(int) * (tabs->len_b));
	if (copy_b == NULL)
		free_and_exit(tabs);
	while (i < tabs->len_b)
	{
		copy_b[i] = (tabs->tab_b)[i];
		i++;
	}
	b_sorted(copy_b, tabs);
	if (tabs->len_b % 2 == 0)
		tabs->mediane_b_tmp = copy_b[tabs->len_b / 2];
	else
		tabs->mediane_b_tmp = copy_b[tabs->len_b / 2 + 1];
	return (copy_b);
}
