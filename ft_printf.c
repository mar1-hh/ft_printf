/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadaou <msaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 13:27:18 by msaadaou          #+#    #+#             */
/*   Updated: 2024/11/26 09:45:27 by msaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *size)
{
	write(1, &c, 1);
	*size += 1;
}

void	check_format(char c, va_list args, int *size)
{
	if (c == 'c')
		ft_putchar(va_arg(args, int), size);
	else if (c == 's')
		ft_putstr(va_arg(args, char *), size);
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(args, int), size);
	else if (c == 'p')
		ft_putmem(va_arg(args, unsigned long), 0, size);
	else if (c == 'x')
		ft_putadr(va_arg(args, unsigned int), 0, size);
	else if (c == 'X')
		ft_putadr(va_arg(args, unsigned int), 1, size);
	else if (c == 'u')
		ft_putnbr_unsigned(va_arg(args, unsigned int), size);
	else
		ft_putchar(c, size);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	int			size;

	size = 0;
	va_start(args, format);
	while (*format)
	{
		if (*(format + 1) && *(format) == '%')
		{
			format++;
			check_format(*format, args, &size);
		}
		else if (*format != '%')
			ft_putchar(*format, &size);
		format++;
	}
	va_end(args);
	return (size);
}
