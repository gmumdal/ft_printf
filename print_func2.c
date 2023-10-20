/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_func2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongsh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:50:33 by hyeongsh          #+#    #+#             */
/*   Updated: 2023/10/20 17:17:46 by hyeongsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexa(unsigned int un, int count, char *hexa)
{
	if (un < 16)
	{
		if (ft_putchar(hexa[un]) == -1)
			return (-1);
		count++;
	}
	else
	{
		count = ft_puthexa(un / 16, count, hexa);
		if (count == -1)
			return (-1);
		if (ft_putchar(hexa[un % 16]) == -1)
			return (-1);
		count++;
	}
	return (count);
}

int	ft_putaddr(unsigned long long ln, int count, char *hexa)
{
	if (ln == 0)
	{
		count += ft_putstr("0x");
		if (count == -1)
			return (-1);
	}
	else
	{
		count = ft_putaddr(ln / 16, count, hexa);
		if (count == -1)
			return (-1);
		if (ft_putchar(hexa[ln % 16]) == -1)
			return (-1);
		count++;
	}
	return (count);
}

int	ft_putunsign(unsigned int un, int count)
{
	if (un < 10)
	{
		if (ft_putchar(un + '0') == -1)
			return (-1);
		count++;
	}
	else
	{
		count = ft_putunsign(un / 10, count);
		if (count == -1)
			return (-1);
		if (ft_putchar(un % 10 + '0') == -1)
			return (-1);
		count++;
	}
	return (count);
}
