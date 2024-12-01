/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadaou <msaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:27:23 by msaadaou          #+#    #+#             */
/*   Updated: 2024/11/25 15:38:29 by msaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_putchar(char c, int *size)
{
	write(1, &c, 1);
	*size += 1;
}

void	check_flag(char **flag, int *arr)
{
	while (**flag && is_flag(**flag))
	{
		if (**flag == '+')
		{
			arr[0] = 1;
			arr[1] = 0;
		}
		else if (**flag == ' ')
		{
			if (!arr[0] && arr[1] != -1)
				arr[1] = 1;
		}
		else
			arr[2] = 1;
		(*flag)++;
	}
}

void	check_format(char c, va_list args, int *size, int *arr)
{
	if (c == 'c')
		ft_putchar(va_arg(args, int), size);
	else if (c == 's')
		ft_putstr(va_arg(args, char *), size);
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(args, int), size, arr);
	else if (c == 'p')
		ft_putmem(va_arg(args, unsigned long), 0, size);
	else if (c == 'x')
		ft_putadr(va_arg(args, unsigned int), 0, size, arr);
	else if (c == 'X')
		ft_putadr(va_arg(args, unsigned int), 1, size, arr);
	else if (c == 'u')
		ft_putnbr_unsigned(va_arg(args, unsigned int), size);
	else
		ft_putchar(c, size);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	int			size;
	int			arr[3];

	ft_bzero(arr, 3 * sizeof(int));
	size = 0;
	va_start(args, format);
	while (*format)
	{
		if (*(format + 1) && *(format) == '%')
		{
			format++;
			if (is_flag(*format))
				check_flag((char **)&format, arr);
			check_format(*format, args, &size, arr);
		}
		else if (*format != '%')
			ft_putchar(*format, &size);
		format++;
	}
	va_end(args);
	return (size);
}
