/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buf_func_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongsh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:06:47 by hyeongsh          #+#    #+#             */
/*   Updated: 2023/10/26 17:06:55 by hyeongsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

t_buf	*buf_setting(void)
{
	t_buf	*tmp;

	tmp = (t_buf *)malloc(sizeof(t_buf));
	if (tmp == 0)
		return (0);
	tmp->size = 2048;
	tmp->index = 0;
	tmp->buffer = ft_calloc(tmp->size + 1);
	if (tmp->buffer == 0)
	{
		free(tmp);
		return (0);
	}
	return (tmp);
}

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
			free(info);
		}
	}
	return (1);
}

int	buf_char(t_buf *buf, char c)
{
	char	*tmp;
	int		i;

	if (buf->index > buf->size - 1)
	{
		buf->size *= 2;
		tmp = ft_calloc(buf->size + 1);
		if (tmp == 0)
			return (0);
		i = -1;
		while (++i < buf->index)
			tmp[i] = buf->buffer[i];
		free(buf->buffer);
		buf->buffer = tmp;
	}
	buf->buffer[buf->index] = c;
	buf->index++;
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
	while (i < info->field)
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
