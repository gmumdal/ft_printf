/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongsh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 14:17:14 by hyeongsh          #+#    #+#             */
/*   Updated: 2023/10/20 17:21:21 by hyeongsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	va_list	lst;
	int		total;
	int		index;
	int		error;

	va_start(lst, s);
	index = 0;
	total = 0;
	while (s[index])
	{
		if (s[index] != '%')
			error = ft_putchar(s[index]);
		else
			error = check_n_print(s[++index], lst);
		if (error == -1)
			return (-1);
		total += error;
		index++;
	}
	return (total);
}

int	check_n_print(char c, va_list lst)
{
	int	error;

	if (c == 'c')
		error = ft_putchar(va_arg(lst, int));
	else if (c == 's')
		error = ft_putstr(va_arg(lst, char *));
	else if (c == 'd' || c == 'i')
		error = ft_putnbr(va_arg(lst, int), 0);
	else if (c == 'x')
		error = ft_puthexa(va_arg(lst, unsigned int), 0, "0123456789abcdef");
	else if (c == 'X')
		error = ft_puthexa(va_arg(lst, unsigned int), 0, "0123456789ABCDEF");
	else if (c == 'p')
		error = ft_putaddr(va_arg(lst, unsigned long long),
				0, "0123456789abcdef");
	else if (c == 'u')
		error = ft_putunsign(va_arg(lst, unsigned int), 0);
	else if (c == '%')
		error = ft_putchar(c);
	else
		return (0);
	return (error);
}
/*
int	main(void)
{
	int a;
	char b[] = "adjfkasdjfkajslf";
	a = ft_printf("%s\n", b);
	ft_printf("a = %d\n", a);
	a = printf("%s\n", b);
	printf("a = %d\n", a);
}*/
