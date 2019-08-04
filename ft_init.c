/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouzar <mobouzar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 17:41:24 by mobouzar          #+#    #+#             */
/*   Updated: 2019/07/30 00:52:34 by mobouzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_init(t_format *f)
{
	f->flag[0] = '\0';
	f->width = 0;
	f->precision = -1;
	f->l = -1;
	f->ll = -1;
	f->h = -1;
	f->hh = -1;
}

int		ft_flag(t_format *f, const char *format)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (ft_strchr("#0+- ", format[++i]) && j < 5)
	{
		if (format[i] != f->flag[j - 1])
			f->flag[j++] = format[i];
	}
	f->flag[j] = '\0';
	return (i);
}

int		ft_width(t_format *f, const char *format, int i)
{
	int	j;

	j = i;
	while (format[j] >= '0' && format[j] <= '9')
		j++;
	f->width = ft_atoi(format + i);
	return (j);
}

int		ft_precision(t_format *f, const char *format, int i)
{
	int		j;
	char	*tmp;

	j = i + 1;
	if (format[i] == '.')
	{
		while (format[j] >= '0' && format[j] <= '9')
			j++;
		tmp = ft_strsub(format, i + 1, j);
		f->precision = ft_atoi(tmp);
		free(tmp);
	}
	return (j);
}

char	*ft_cut_modifier(t_format f, const char *format)
{
	char	*modifier;
	int		i;
	int		j;

	i = 0;
	j = 0;
	modifier = ft_strnew(2);
	if (ft_strchr(format, 'h') || ft_strchr(format, 'l'))
	{
		while (format[j] && format[j] != 'h' && format[j] != 'l')
			j++;
		while (format[j] != f.specifier)
			modifier[i++] = format[j++];
		modifier[i] = '\0';
	}
	return (modifier);
}

void	ft_modifier(t_format *f, const char *format)
{
	char	*length_mo;

	length_mo = ft_cut_modifier(*f, format);
	if (!ft_strcmp(length_mo, "hh"))
		f->hh = 1;
	if (!ft_strcmp(length_mo, "h"))
		f->h = 1;
	if (!ft_strcmp(length_mo, "ll"))
		f->ll = 1;
	if (!ft_strcmp(length_mo, "l"))
		f->l = 1;
	free(length_mo);
}
