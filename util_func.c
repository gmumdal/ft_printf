/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongsh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 15:08:40 by hyeongsh          #+#    #+#             */
/*   Updated: 2023/10/22 22:28:03 by hyeongsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_init(char c, char *s)
{
	int	count;

	count = 0;
	while (s[count])
	{
		if (s[count] == c)
			return (count);
		count++;
	}
	return (-1);
}

char	*ft_calloc(int count, int size)
{
	char	*tmp;
	int		i;

	tmp = (char *)malloc(count * size);
	if (tmp == 0)
		return (0);
	i = 0;
	while (i < count * size)
		tmp[i++] = 0;
	return (tmp);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}

char	*ft_realloc(char *buf, int size)
{
	char	*tmp;
	int		i;

	tmp = ft_calloc(size, 1);
	if (tmp == 0)
		return (0);
	i = 0;
	while (buf[i])
	{
		tmp[i] = buf[i];
		i++;
	}
	return (tmp);
}
