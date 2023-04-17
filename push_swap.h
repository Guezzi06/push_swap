/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguezzi <aguezzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:04:04 by aguezzi           #+#    #+#             */
/*   Updated: 2023/04/12 14:34:30 by aguezzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "libft/ft_printf.h"
# include <stdlib.h>

typedef struct s_tableau
{
	int		*tab_a;
	int		*tab_b;
	int		*pile_sorted;
	int		len_a;
	int		len_b;
	int		max_pile;
	int		min_pile;
	int		max_a_tmp;
	int		min_a_tmp;
	int		index_min_a_tmp;
	int		index_max_a_tmp;
	int		max_b_tmp;
	int		min_b_tmp;
	int		index_min_b_tmp;
	int		index_max_b_tmp;
	int		total;
	int		mediane;
	int		mediane_b_tmp;
	char	**split_numbers;
}	t_tableau;

int		pile_is_sorted(t_tableau *tabs);
int		ft_atoi(const char *n);
int		check_doublon(t_tableau *tabs);
int		check_numbers(int argc, char **argv);
void	create_piles(int argc, char **argv, t_tableau *tabs);
void	init_tableau(t_tableau *tabs);
void	init_ptr(t_tableau *tabs);
void	calcul_min_max(t_tableau *tabs);
void	sorted_list(t_tableau *tabs);
void	copy(t_tableau *tabs);
void	sa_sb(int instruction, t_tableau *tabs);
void	pa(t_tableau *tabs);
void	pb(t_tableau *tabs);
void	ra_rb(int instruction, t_tableau *tabs);
void	rra_rrb(int instruction, t_tableau *tabs);
void	rr(t_tableau *tabs);
void	algo_2numbers(int *tab, t_tableau *tabs);
void	algo_3numbers(int *tab, t_tableau *tabs);
void	algo_4numbers(int *tab, t_tableau *tabs);
void	algo_5numbers(int *tab, t_tableau *tabs);
void	algo_10numbers(int *tab, t_tableau *tabs);
void	suite_algo10(int *tab, t_tableau *tabs);
void	algo_big_numbers(t_tableau *tabs);
void	suite_algo_big(t_tableau *tabs);
void	algo_2_b(int *tab, t_tableau *tabs);
void	algo_3_b(int *tab, t_tableau *tabs);
void	algo_4_b(int *tab, t_tableau *tabs);
void	algo_5_b(int *tab, t_tableau *tabs);
int		*calcul_mediane_b(t_tableau *tabs);
void	b_sorted(int *copy, t_tableau *tabs);
void	min_max_tmp(t_tableau *tabs);
void	min_max_a_tmp(t_tableau *tabs);
void	min_max_b_tmp(t_tableau *tabs);
void	optimisation(int ref, t_tableau *tabs);
void	opti_first_if(int i, int j, int ref, t_tableau *tabs);
void	opti_first_part(int i, int j, int ref, t_tableau *tabs);
void	opti_second_part(int i, int j, int ref, t_tableau *tabs);
void	else_second_part(int i, int j, int ref, t_tableau *tabs);
void	opti_third_part(int i, int j, int ref, t_tableau *tabs);
void	else_third_part(int i, int j, int ref, t_tableau *tabs);
void	choose_algo(int numbers, int *tab, t_tableau *tabs);
void	split_numbers(char **argv, t_tableau *tabs);
void	split_create(int count, t_tableau *tabs);
void	check_errors_split(int count, t_tableau *tabs);
long	ft_atoi_pswap(char *n, t_tableau *tabs);
void	check_error_int(char *n, long nbr, t_tableau *tabs);
void	free_and_exit(t_tableau *tabs);

#endif
