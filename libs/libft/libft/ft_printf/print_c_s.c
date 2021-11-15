/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnelson <lnelson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 13:35:38 by lnelson           #+#    #+#             */
/*   Updated: 2021/09/11 08:02:38 by lnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include "./printf.h"

int		print_c(char c, t_print *args)
{
	if (args->wd > 1)
	{
		if (args->min != 1)
		{
			ft_putnchar_fd(' ', args->wd - 1, 1);
			ft_putchar_fd(c, 1);
		}
		else
		{
			ft_putchar_fd(c, 1);
			ft_putnchar_fd(' ', args->wd - 1, 1);
		}
	}
	else
		ft_putchar_fd(c, 1);
	return (args->wd > 1 ? args->wd : 1);
}

int		print_s_null(t_print *args)
{
	int	wd;
	int	prc;

	wd = args->wd;
	prc = args->prc;
	if (args->min != 1 && (prc >= 6 || prc < 0))
		ft_putnchar_fd(' ', wd - 6, 1);
	else if (args->min != 1 && (prc >= 0 && prc < 6))
		ft_putnchar_fd(' ', wd - args->prc, 1);
	if (args->prc < 6 && args->prc > 0)
		write(1, "(null)", args->prc);
	else if (args->prc >= 6 || args->prc < 0)
		write(1, "(null)", 6);
	if (args->min == 1)
	{
		if (prc >= 6 || prc < 0)
			ft_putnchar_fd(' ', wd - 6, 1);
		else if (prc >= 0 && prc < 6)
			ft_putnchar_fd(' ', wd - args->prc, 1);
	}
	if (wd <= prc && prc > 0 && prc < 6)
		return (prc);
	if (args->prc >= 6 || args->prc < 0)
		return (args->wd > 6 ? args->wd : 6);
	return (args->wd > 0 ? args->wd : 0);
}

int		print_s(char *str, t_print *args)
{
	int l;
	int strl;

	if (str == NULL)
		return (print_s_null(args));
	strl = ft_strlen(str);
	l = ((args->prc >= 0 && args->prc <= strl) ? args->prc : strl);
	if (args->wd > (args->prc > strl ? strl : l))
	{
		if (!(args->min != 1))
			ft_putnstr_fd(str, l, 1);
		ft_putnchar_fd(' ', args->wd - (args->prc > strl ? strl : l), 1);
		if (args->min != 1)
			ft_putnstr_fd(str, l, 1);
	}
	else
		ft_putnstr_fd(str, args->prc, 1);
	if (str != NULL && *str == 0)
		return (args->wd != -1 ? args->wd : 0);
	if (args->wd >= l)
		return (args->wd);
	return (args->prc > strl ? strl : l);
}
*/