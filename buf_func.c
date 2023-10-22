/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buf_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongsh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 22:21:45 by hyeongsh          #+#    #+#             */
/*   Updated: 2023/10/22 22:29:43 by hyeongsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	buf_input(t_buf *buf, char *s, va_list lst)
{
	t_info	*info;

	while (*s)
	{
		if (*s != '%')
		{
			if (buf_char(buf, *s++) == 0)
				return (0);
		}
		else
		{
			s++;
			info = check_option(&s);
			if (info == 0)
				return (0);
			if (buf_join(buf, info, lst) == 0)
			{
				free(info);
				return (0);
			}
		}
	}
	return (1);
}

int	buf_join(t_buf *buf, t_info *info, va_list lst)
{
	char	*tmp;
	int		i;

	tmp = make_tmp(info, lst);
	if (tmp == 0)
		return (0);
	i = 0;
	while (tmp[i])
	{
		if (buf_char(buf, tmp[i++]) == 0)
		{
			free(tmp);
			return (0);
		}
	}
	free(tmp);
	return (1);
}

t_buf	*buf_setting(void)
{
	t_buf	*buf;

	buf = (t_buf *)malloc(sizeof(t_buf));
	if (buf == 0)
		return (0);
	buf->size = 2048;
	buf->cur = 0;
	buf->buffer = ft_calloc(buf->size + 1, 1);
	if (buf->buffer == 0)
	{
		free(buf);
		return (0);
	}
	return (buf);
}

int	buf_char(t_buf *buf, char c)
{
	char	*tmp;

	if (buf->cur > buf->size - 2)
	{
		buf->size *= 2;
		tmp = ft_realloc(buf->buffer, buf->size + 1);
		if (tmp == 0)
			return (0);
		free(buf->buffer);
		buf->buffer = tmp;
	}
	buf->buffer[buf->cur] = c;
	buf->cur++;
	return (1);
}
