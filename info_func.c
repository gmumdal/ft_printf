/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongsh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 15:04:44 by hyeongsh          #+#    #+#             */
/*   Updated: 2023/10/22 22:25:46 by hyeongsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_info	*check_option(char **s)
{
	t_info	*info;

	info = info_init();
	if (info == 0)
		return (0);
	while (is_init(**s, "+-# 0") > -1)
	{
		info_option(**s, info);
		(*s)++;
	}
	while (is_init(**s, "0123456789") > -1)
		info_field(s, info);
	while (is_init(**s, ".") > -1)
		info_pre(s, info);
	if (is_init(**s, "+-# ") > -1)
	{
		free(info);
		return (0);
	}
	info->type = **s;
	(*s)++;
	return (info);
}

t_info	*info_init(void)
{
	t_info	*info;

	info = (t_info *)malloc(sizeof(t_info));
	if (info == 0)
		return (0);
	info->field = 0;
	info->shop = 0;
	info->left = 0;
	info->pre = -1;
	info->type = 0;
	info->plma = 0;
	info->blank = 0;
	info->zero = 0;
	return (info);
}

void	info_option(char c, t_info *info)
{
	if (c == '+')
		info->plma = 1;
	else if (c == '-')
		info->left = 1;
	else if (c == '#')
		info->shop = 1;
	else if (c == ' ')
		info->blank++;
	else
		info->zero = 1;
}

void	info_field(char **s, t_info *info)
{
	while (is_init(**s, "0123456789") > -1)
	{
		info->field = info->field * 10 + (**s - '0');
		(*s)++;
	}
}

void	info_pre(char **s, t_info *info)
{
	(*s)++;
	info->pre = 0;
	while (is_init(**s, "0123456789") > -1)
	{
		info->pre = info->pre * 10 + (**s - '0');
		(*s)++;
	}
}
