/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnelson <lnelson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 13:35:46 by lnelson           #+#    #+#             */
/*   Updated: 2021/09/11 08:02:52 by lnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include "./printf.h"

void	f_print_flag_utils(t_print *args, double nbr)
{
	if (nbr < 0)
		write(1, "-", 1);
	else
	{
		if (args->pls == 1)
			write(1, "+", 1);
		else
			write(1, " ", 1);
	}
}

void	pf_float(double f, t_print *args)
{
	int		i;
	double	second;
	int		temp;

	second = (f - (int)f) * (f >= 0 ? 1 : -1);
	temp = 0;
	i = 0;
	ft_putnbr_fd((int)f * (f >= 0 ? 1 : -1), 1);
	if (args->ash == 1 || second > 0)
		write(1, ".", 1);
	while (second != 0 && i < (args->prc == -1 ? 6 : args->prc))
	{
		second *= 10;
		temp = (int)second;
		ft_putchar_fd(temp + 48, 1);
		second -= temp;
		i++;
	}
}

int		float_len(double f, t_print *args)
{
	int res;
	int second;
	int i;

	i = 0;
	res = (int)f * (f < 0 ? -1 : 1);
	second = ((f * (f < 0 ? -1 : 1)) - res) * (f < 0 ? -1 : 1);
	if (args->ash == 1 || (second != 0 && args->prc > 0))
		res++;
	while (second != 0 && i < (args->prc == -1 ? 6 : args->prc))
	{
		second *= 10;
		second -= (int)second;
		i++;
		res++;
	}
	return (res);
}

void	print_f_norme(double nbr, t_print *args)
{
	ft_putnchar_fd(' ', args->wd - args->sz, 1);
	if (args->pls == 1 || args->spc == 1 || nbr < 0)
		f_print_flag_utils(args, nbr);
	pf_float(nbr, args);
}

int		print_f(double nbr, t_print *args)
{
	args->sz = float_len(nbr, args);
	args->sz += (args->pls == 1 || args->spc == 1 || nbr < 0) ? 1 : 0;
	if (args->min == 1)
	{
		if (args->pls == 1 || args->spc == 1 || nbr < 0)
			f_print_flag_utils(args, nbr);
		pf_float(nbr, args);
		ft_putnchar_fd(' ', args->wd - args->sz, 1);
	}
	else
	{
		if (args->zer == 1)
		{
			if (args->pls == 1 || args->spc == 1 || nbr < 0)
				f_print_flag_utils(args, nbr);
			ft_putnchar_fd('0', args->wd - args->sz, 1);
			pf_float(nbr, args);
			return (args->wd > args->sz ? args->wd : args->sz);
		}
		print_f_norme(nbr, args);
	}
	return (args->wd > args->sz ? args->wd : args->sz);
}
*/
