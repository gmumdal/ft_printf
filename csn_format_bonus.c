/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   csn_format_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongsh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:06:58 by hyeongsh          #+#    #+#             */
/*   Updated: 2023/10/26 17:31:05 by hyeongsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*make_char(t_info *info, char c)
{
	char	*tmp;
	int		i;

	if (info->field == -1)
		info->field = 1;
	tmp = ft_calloc(info->field + 1);
	if (tmp == 0)
		return (0);
	i = -1;
	while (++i < info->field)
			tmp[i] = ' ';
	if (info->left == 0)
		tmp[info->field - 1] = c;
	else if (info->left == 1)
		tmp[0] = c;
	return (tmp);
}

char	*make_str(t_info *info, char *s1, char *s)
{
	char	*tmp;
	int		len;
	int		i;

	if (s1 != NULL)
		s = s1;
	len = ft_strlen(s);
	if (info->pre == -1 || info->pre > len)
		info->pre = len;
	else if (info->pre < len)
		len = info->pre;
	if (info->field < len)
		info->field = len;
	tmp = ft_calloc(info->field + 1);
	if (tmp == 0)
		return (0);
	i = -1;
	while (++i < info->field)
		tmp[i] = ' ';
	if (info->left == 0)
		ft_strncpy(tmp + info->field - info->pre, s, info->pre);
	else if (info->left == 1)
		ft_strncpy(tmp, s, info->pre);
	return (tmp);
}

char	*make_normal(t_info *info, char c)
{
	char	*tmp;
	char	fill;
	int		i;

	if (info->type == 0)
		return (ft_calloc(1));
	fill = ' ';
	if (info->left == 0 && info->zero == 1)
		fill = '0';
	if (info->field == -1)
		info->field = 1;
	tmp = ft_calloc(info->field + 1);
	if (tmp == 0)
		return (0);
	i = -1;
	while (++i < info->field)
		tmp[i] = fill;
	if (info->left == 0)
		tmp[info->field - 1] = c;
	else if (info->left == 1)
		tmp[0] = c;
	return (tmp);
}
