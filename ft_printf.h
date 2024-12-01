/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadaou <msaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 13:27:38 by msaadaou          #+#    #+#             */
/*   Updated: 2024/11/19 11:02:31 by msaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
void	ft_putchar(char c, int *size);
void	ft_putstr(char *str, int *size);
void	ft_putnbr(int n, int *size);
void	ft_putnbr_unsigned(unsigned int nb, int *size);
void	ft_putmem(unsigned long add_n, int flag, int *size);
void	ft_putadr(unsigned int add_n, int flag_2, int *size);

#endif