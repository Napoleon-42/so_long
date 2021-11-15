/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_i_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnelson <lnelson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 13:35:54 by lnelson           #+#    #+#             */
/*   Updated: 2021/09/11 08:03:13 by lnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include "./printf.h"

static void		pf_putnbr(int nbr, t_print *args)
{
	unsigned int	nb;

	if (nbr < 0)
		nb = -nbr;
	else
		nb = nbr;
	if (nb / 10 > 0)
		pf_putnbr(nb / 10, args);
	ft_putchar_fd((nb % 10 + 48), 1);
}

static int		nbrlen(int nbr)
{
	int				i;
	unsigned int	nb;

	i = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
		nb = -nbr;
	else
		nb = nbr;
	while (nb > 0)
	{
		i++;
		nb = nb / 10;
	}
	return (i);
}

void			print_i_d_norme(int nbr, t_print *args)
{
	ft_putnchar_fd(' ', args->wd - args->sz, 1);
	if (args->pls == 1 || args->spc == 1 || nbr < 0)
		print_flag_utils(args, nbr);
	ft_putnchar_fd('0', args->prc - nbrlen(nbr), 1);
	pf_putnbr(nbr, args);
}

static int		null_precision_nbr(int with)
{
	ft_putnchar_fd(' ', with, 1);
	return (with == -1 ? 0 : with);
}

int				print_i_d(int nbr, t_print *args)
{
	if (args->prc == 0 && nbr == 0)
		return (null_precision_nbr(args->wd));
	args->sz = nbrlen(nbr) < args->prc ? args->prc : nbrlen(nbr);
	args->sz += (args->pls == 1 || args->spc == 1 || nbr < 0) ? 1 : 0;
	if (args->min == 1)
	{
		if (args->pls == 1 || args->spc == 1 || nbr < 0)
			print_flag_utils(args, nbr);
		ft_putnchar_fd('0', args->prc - nbrlen(nbr), 1);
		pf_putnbr(nbr, args);
		ft_putnchar_fd(' ', args->wd - args->sz, 1);
	}
	else
	{
		if (args->zer == 1 && args->prc < 0)
		{
			if (args->pls == 1 || args->spc == 1 || nbr < 0)
				print_flag_utils(args, nbr);
			ft_putnchar_fd('0', args->wd - args->sz, 1);
			pf_putnbr(nbr, args);
			return (args->wd > args->sz ? args->wd : args->sz);
		}
		print_i_d_norme(nbr, args);
	}
	return (args->wd > args->sz ? args->wd : args->sz);
}
*/
