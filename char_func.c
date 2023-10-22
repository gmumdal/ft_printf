/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_func1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongsh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 17:40:38 by hyeongsh          #+#    #+#             */
/*   Updated: 2023/10/22 22:11:21 by hyeongsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*make_char(t_info *info, char c)
{
	char	*tmp;
	int		i;

	if (info->pre > 0)
	   return (0);
	if (info->shop + info->plma + info->zero + info->blank > 0)
		return (0);
	if (info->field == 0)
		info->field = 1;
	tmp = ft_calloc(info->field + 1, 1);
	if (tmp == 0)
		return (0);
	if (info->left == 0)
		tmp[info->field - 1] = c;
	else if (info->left == 1)
		tmp[0] = c;
	i = -1;
	while (++i < info->field)
	{
		if (tmp[i] == 0)
			tmp[i] = ' ';
	}
	return (tmp);
}
