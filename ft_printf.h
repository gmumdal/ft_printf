/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongsh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:53:37 by hyeongsh          #+#    #+#             */
/*   Updated: 2023/10/20 17:04:41 by hyeongsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *s, ...);
int	check_n_print(char c, va_list lst);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putnbr(long long ln, int count);
int	ft_puthexa(unsigned int un, int count, char *hexa);
int	ft_putaddr(unsigned long long ln, int count, char *hexa);
int	ft_putunsign(unsigned int un, int count);

#endif
