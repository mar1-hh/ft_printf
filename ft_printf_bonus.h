/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadaou <msaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:27:44 by msaadaou          #+#    #+#             */
/*   Updated: 2024/11/25 15:46:45 by msaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
void	ft_putchar(char c, int *size);
void	ft_putstr(char *str, int *size);
void	ft_putnbr(int n, int *size, int *arr);
void	ft_putnbr_unsigned(unsigned int nb, int *size);
void	ft_putmem(unsigned long add_n, int flag, int *size);
void	ft_putadr(unsigned int add_n, int flag_2, int *size, int *arr);
void	ft_bzero(void *s, size_t n);
int		is_format(char c);
int		is_flag(char c);

#endif