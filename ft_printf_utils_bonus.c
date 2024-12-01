/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadaou <msaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:28:23 by msaadaou          #+#    #+#             */
/*   Updated: 2024/11/26 09:51:58 by msaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_putstr(char *str, int *size)
{
	size_t	i;

	if (!str)
	{
		ft_putstr("(null)", size);
		return ;
	}
	i = 0;
	while (str[i])
	{
		ft_putchar(str[i], size);
		i++;
	}
}

void	ft_putnbr(int n, int *size, int *arr)
{
	long	nb;

	nb = n;
	if (nb < 0)
		ft_bzero(arr, 2 * sizeof(int));
	if (arr[0])
	{
		ft_putchar('+', size);
		arr[0] = 0;
	}
	else if (arr[1])
	{
		ft_putchar(' ', size);
		arr[1] = 0;
	}
	if (nb < 0)
	{
		ft_putchar('-', size);
		nb = -nb;
	}
	if (nb >= 10)
		ft_putnbr(nb / 10, size, arr);
	ft_putchar(nb % 10 + '0', size);
}

void	ft_putnbr_unsigned(unsigned int nb, int *size)
{
	if (nb >= 10)
		ft_putnbr_unsigned(nb / 10, size);
	ft_putchar(nb % 10 + '0', size);
}

void	ft_putadr(unsigned int add_n, int flag_2, int *size, int *arr)
{
	char	*str;

	if (arr[2] && add_n)
	{
		if (flag_2)
			ft_putstr("0X", size);
		else
			ft_putstr("0x", size);
		arr[2] = 0;
	}
	str = "0123456789abcdef";
	if (flag_2)
		str = "0123456789ABCDEF";
	if (add_n >= 16)
		ft_putadr(add_n / 16, flag_2, size, arr);
	ft_putchar(str[add_n % 16], size);
}

void	ft_putmem(unsigned long add_n, int flag, int *size)
{
	char	*str;

	str = "0123456789abcdef";
	if (!flag)
	{
		ft_putstr("0x", size);
		flag = 1;
	}
	if (add_n >= 16)
		ft_putmem(add_n / 16, flag, size);
	ft_putchar(str[add_n % 16], size);
}
