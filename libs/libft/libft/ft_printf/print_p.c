/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnelson <lnelson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 13:36:01 by lnelson           #+#    #+#             */
/*   Updated: 2021/09/11 08:03:26 by lnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include "./printf.h"

int		ui_len(uintmax_t nbr)
{
	int i;

	if (nbr == 0)
		return (1);
	i = 0;
	while (nbr != 0)
	{
		i++;
		nbr /= 16;
	}
	return (i);
}

void	put_uint_base(uintmax_t nbr, char *str)
{
	if (nbr >= 16)
		put_uint_base(nbr / 16, str);
	ft_putchar_fd(str[nbr % 16], 1);
}

int		print_p_zero(t_print *args)
{
	int diff;

	diff = (args->prc == 0 ? 2 : 3);
	if (args->min == 1)
	{
		write(1, "0x0", diff);
		ft_putnchar_fd(' ', args->wd - diff, 1);
	}
	else
	{
		ft_putnchar_fd(' ', args->wd - diff, 1);
		write(1, "0x0", diff);
	}
	return (diff < args->wd ? args->wd : diff);
}

void	utils(t_print *args)
{
	write(1, "0x", 2);
	ft_putnchar_fd('0', args->wd - args->sz, 1);
}

int		print_p(uintmax_t nbr, t_print *args)
{
	if (nbr == 0)
		return (print_p_zero(args));
	args->sz = (ui_len(nbr) < args->prc ? args->prc : ui_len(nbr)) + 2;
	if (args->min == 1)
	{
		write(1, "0x", 2);
		put_uint_base(nbr, "0123456789abcdef");
		if (args->wd > args->sz)
			ft_putnchar_fd(' ', args->wd - args->sz, 1);
	}
	else
	{
		if (args->zer == 1 && args->wd > args->sz)
			utils(args);
		else if (args->wd > args->sz)
			ft_putnchar_fd(' ', args->wd - args->sz, 1);
		if (args->zer != 1)
			write(1, "0x", 2);
		if (args->prc > ui_len(nbr))
			ft_putnchar_fd('0', args->prc - ui_len(nbr), 1);
		put_uint_base(nbr, "0123456789abcdef");
	}
	return ((args->wd > args->sz) ? args->wd : args->sz);
}
*/
