/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_instructions_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguezzi <aguezzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:58:50 by aguezzi           #+#    #+#             */
/*   Updated: 2023/04/12 15:33:09 by aguezzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra_rb(int instruction, t_tableau *tabs)
{
	int	*ptr;
	int	len;
	int	save;
	int	i;

	i = 0;
	if (instruction == 1)
	{
		ptr = tabs->tab_a;
		len = tabs->len_a;
		ft_printf("ra\n");
	}
	else
	{
		ptr = tabs->tab_b;
		len = tabs->len_b;
		ft_printf("rb\n");
	}
	save = ptr[0];
	while (i < len - 1)
	{
		ptr[i] = ptr[i + 1];
		i++;
	}
	ptr[len - 1] = save;
}

void	rra_rrb(int instruction, t_tableau *tabs)
{
	int	*ptr;
	int	len;
	int	save;
	int	i;

	if (instruction == 1)
	{
		ptr = tabs->tab_a;
		len = tabs->len_a;
		ft_printf("rra\n");
	}
	else
	{
		ptr = tabs->tab_b;
		len = tabs->len_b;
		ft_printf("rrb\n");
	}
	i = len - 1;
	save = ptr[len - 1];
	while (i > 0)
	{
		ptr[i] = ptr[i - 1];
		i--;
	}
	ptr[0] = save;
}

void	rr(t_tableau *tabs)
{
	int	*ptr;
	int	len;
	int	save;
	int	i;

	i = -1;
	ptr = tabs->tab_a;
	len = tabs->len_a;
	save = ptr[0];
	while (++i < len - 1)
		ptr[i] = ptr[i + 1];
	ptr[len - 1] = save;
	ptr = tabs->tab_b;
	len = tabs->len_b;
	save = ptr[0];
	i = -1;
	while (++i < len - 1)
		ptr[i] = ptr[i + 1];
	ptr[len - 1] = save;
	ft_printf("rr\n");
}
