/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_func1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongsh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:49:35 by hyeongsh          #+#    #+#             */
/*   Updated: 2023/10/20 17:09:33 by hyeongsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	count;

	count = 0;
	while (s[count] != 0)
	{
		if (ft_putchar(s[count]) == -1)
			return (-1);
		count++;
	}
	return (count);
}

int	ft_putnbr(long long ln, int count)
{
	if (ln < 0)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		count++;
		ln = -ln;
	}
	if (ln < 10)
	{
		if (ft_putchar(ln + '0') == -1)
			return (-1);
		count++;
	}
	else
	{
		count = ft_putnbr(ln / 10, count);
		if (count == -1)
			return (-1);
		if (ft_putchar(ln % 10 + '0') == -1)
			return (-1);
		count++;
	}
	return (count);
}
