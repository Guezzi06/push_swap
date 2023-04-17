/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguezzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:22:56 by aguezzi           #+#    #+#             */
/*   Updated: 2022/11/16 14:54:01 by aguezzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (! ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')))
	{
		if (! (c >= '0' && c <= '9'))
			return (0);
	}
	return (1);
}
