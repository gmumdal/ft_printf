/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xp_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongsh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 13:34:46 by hyeongsh          #+#    #+#             */
/*   Updated: 2023/10/26 16:05:59 by hyeongsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*make_hexa(t_info *info, unsigned long nbr, char *hexa_base)
{
	char	*tmp;
	char	*hexa_num;

	hexa_num = ft_itoa_hexa(nbr, hexa_base, info);
	if (hexa_num == 0)
		return (0);
	if (info->field < ft_strlen(hexa_num))
		info->field = ft_strlen(hexa_num);
	tmp = ft_calloc(info->field + 1);
	if (tmp == 0)
	{
		free(hexa_num);
		return (0);
	}
	if (info->left == 1)
		ft_strncpy(tmp, hexa_num, ft_strlen(hexa_num));
	else if (info->left == 0)
		ft_strncpy(&tmp[info->field - ft_strlen(hexa_num)],
			hexa_num, ft_strlen(hexa_num));
	fill_blank(tmp, info);
	free(hexa_num);
	return (tmp);
}

void	hexa_len_flag(unsigned long nbr, t_info *info, int *len, int *flag)
{
	if (nbr == 0)
		*len = 1;
	else if ((nbr != 0 && info->shop == 1) || info->type == 'p')
		*flag = 2;
	while (nbr != 0)
	{
		(*len)++;
		nbr /= 16;
	}
	if (info->type != 'p')
	{
		if (info->pre > *len)
			*len = info->pre;
		if (info->pre == -1 && info->zero == 1
			&& *len + *flag < info->field - *flag)
			*len = info->field - *flag;
	}
}

char	*ft_itoa_hexa(unsigned long nbr, char *hexa_base, t_info *info)
{
	char	*num;
	int		len;
	int		flag;
	int		i;

	flag = 0;
	len = 0;
	hexa_len_flag(nbr, info, &len, &flag);
	num = ft_calloc(len + flag + 1);
	if (num == 0)
		return (0);
	i = 0;
	if (flag == 2)
	{
		num[i++] = hexa_base[0];
		num[i++] = hexa_base[16];
	}
	while (i < len + flag)
	{
		num[i++] = hexa_base[nbr % 16];
		nbr = nbr / 16;
	}
	ft_swap(num, len, flag);
	return (num);
}
