/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongsh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:53:37 by hyeongsh          #+#    #+#             */
/*   Updated: 2023/10/22 22:52:20 by hyeongsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_buf
{
	char	*buffer;
	int		cur;
	int		size;
}	t_buf;

typedef struct s_info
{
	int	field;
	int	shop;
	int	left;
	int	pre;
	int	type;
	int	plma;
	int	blank;
	int	zero;
}	t_info;

int		ft_printf(const char *s, ...);
int		buf_input(t_buf *buf, char *s, va_list lst);
t_info	*check_option(char **s);
int		buf_join(t_buf *buf, t_info *info, va_list lst);
char	*make_tmp(t_info *info, va_list lst);
t_info	*info_init(void);
void	info_option(char c, t_info *info);
void	info_field(char **s, t_info *info);
void	info_pre(char **s, t_info *info);
int		is_init(char c, char *s);
t_buf	*buf_setting(void);
char	*ft_calloc(int count, int size);
int		ft_strlen(char *s);
int		buf_char(t_buf *buf, char c);
char	*make_char(t_info *info, char c);
char	*ft_realloc(char *buf, int size);
char	*make_normal(t_info *info, char c);

#endif
