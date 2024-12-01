/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadaou <msaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:29:14 by msaadaou          #+#    #+#             */
/*   Updated: 2024/11/25 15:30:11 by msaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*c;

	i = 0;
	c = s;
	while (i < n)
		c[i++] = 0;
}

int	is_flag(char c)
{
	return (c == ' ' || c == '+' || c == '#');
}

int	is_format(char c)
{
	return (c == 'd' || c == 'c' || c == 's' || c == 'i'
		|| c == 'x' || c == 'X' || c == 'p');
}
