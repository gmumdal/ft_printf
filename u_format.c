/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_format.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongsh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:32:57 by hyeongsh          #+#    #+#             */
/*   Updated: 2023/10/26 16:05:43 by hyeongsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*make_unsign(t_info *info, unsigned int nbr)
{
	char	*tmp;
	char	*us_num;

	us_num = ft_itoa_unsign(nbr, info);
	if (us_num == 0)
		return (0);
	if (info->field < ft_strlen(us_num))
		info->field = ft_strlen(us_num);
	tmp = ft_calloc(info->field + 1);
	if (tmp == 0)
	{
		free(us_num);
		return (0);
	}
	if (info->left == 1)
		ft_strncpy(tmp, us_num, ft_strlen(us_num));
	else if (info->left == 0)
		ft_strncpy(&tmp[info->field - ft_strlen(us_num)],
			us_num, ft_strlen(us_num));
	fill_blank(tmp, info);
	free(us_num);
	return (tmp);
}

int	unsign_len_check(unsigned int nbr, t_info *info)
{
	int	len;

	len = 0;
	if (nbr == 0)
		len = 1;
	while (nbr != 0)
	{
		len++;
		nbr /= 10;
	}
	if (info->pre > len)
		len = info->pre;
	if (info->pre == -1 && info->zero == 1 && len < info->field)
		len = info->field;
	return (len);
}

char	*ft_itoa_unsign(unsigned int nbr, t_info *info)
{
	char	*num;
	int		len;
	int		i;

	len = unsign_len_check(nbr, info);
	num = ft_calloc(len + 1);
	if (num == 0)
		return (0);
	i = 0;
	while (i < len)
	{
		num[i++] = nbr % 10 + '0';
		nbr = nbr / 10;
	}
	ft_swap(num, len, 0);
	return (num);
}
