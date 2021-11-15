/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnelson <lnelson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 13:36:07 by lnelson           #+#    #+#             */
/*   Updated: 2021/09/11 08:03:36 by lnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include "./printf.h"

static void		pf_putnbr(unsigned int nb, t_print *args)
{
	if (nb / 10 > 0)
		pf_putnbr(nb / 10, args);
	ft_putchar_fd((nb % 10 + 48), 1);
}

static int		nbrlen(unsigned int nb)
{
	int				i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		i++;
		nb = nb / 10;
	}
	return (i);
}

void			print_u_norme(unsigned int nbr, t_print *args)
{
	ft_putnchar_fd(' ', args->wd - args->sz, 1);
	if (args->pls == 1 || args->spc == 1)
		write(1, (args->pls == 1 ? "+" : " "), 1);
	ft_putnchar_fd('0', args->prc - nbrlen(nbr), 1);
	pf_putnbr(nbr, args);
}

static int		null_precision_nbr(int with)
{
	ft_putnchar_fd(' ', with, 1);
	return (with < 0 ? 0 : with);
}

int				print_u(unsigned int nbr, t_print *args)
{
	if (args->prc == 0 && nbr == 0)
		return (null_precision_nbr(args->wd));
	args->sz = nbrlen(nbr) < args->prc ? args->prc : nbrlen(nbr);
	args->sz += (args->pls == 1 || args->spc == 1) ? 1 : 0;
	if (args->min == 1)
	{
		if (args->pls == 1 || args->spc == 1)
			write(1, (args->pls == 1 ? "+" : " "), 1);
		ft_putnchar_fd('0', args->prc - nbrlen(nbr), 1);
		pf_putnbr(nbr, args);
		ft_putnchar_fd(' ', args->wd - args->sz, 1);
	}
	else
	{
		if (args->zer == 1 && args->prc < 0)
		{
			if (args->pls == 1 || args->spc == 1)
				write(1, (args->pls == 1 ? "+" : " "), 1);
			ft_putnchar_fd('0', args->wd - args->sz, 1);
			pf_putnbr(nbr, args);
			return (args->wd > args->sz ? args->wd : args->sz);
		}
		print_u_norme(nbr, args);
	}
	return (args->wd > args->sz ? args->wd : args->sz);
}
*/
