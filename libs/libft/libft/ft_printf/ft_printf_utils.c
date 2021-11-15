/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnelson <lnelson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 13:35:22 by lnelson           #+#    #+#             */
/*   Updated: 2021/09/11 08:01:59 by lnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include "printf.h"

void	print_flag_utils(t_print *args, int nbr)
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

void	init_print(t_print *args)
{
	args->prc = -1;
	args->wd = -1;
	args->zer = -1;
	args->min = -1;
	args->sz = 0;
	args->arg = 0;
	args->ash = -1;
	args->pls = -1;
	args->spc = -1;
}

void	get_param_uts(int num, t_print *args)
{
	if (num < 0)
	{
		args->wd = -num;
		args->min = 1;
	}
	else
		args->wd = num;
	return ;
}

void	get_param_ut(const char **str, va_list *ap, t_print *args)
{
	if (**str == '.')
	{
		(*str)++;
		if (**str == '*')
			args->prc = va_arg(*ap, int);
		else
		{
			args->prc = ft_atoi(*str);
			while (ft_isdigit(**str) == 42)
				(*str)++;
			(*str)--;
		}
	}
	else if (ft_isdigit(**str) == 42)
	{
		args->wd = ft_atoi(*str);
		while (ft_isdigit(**str) == 42)
			(*str)++;
		(*str)--;
	}
}

void	get_param(const char **str, va_list *ap, t_print *args)
{
	(*str)++;
	while (ft_strchr("cspdiuxXnefg%\0", **str) == NULL)
	{
		if (**str == ' ')
			args->spc = 1;
		if (**str == '+')
			args->pls = 1;
		if (**str == '#')
			args->ash = 1;
		if (**str == '-')
			args->min = 1;
		if (**str == '0')
			args->zer = 1;
		if (**str == '*')
			get_param_uts(va_arg(*ap, int), args);
		if (**str == '.' || ft_isalnum(**str))
			get_param_ut(str, ap, args);
		(*str)++;
	}
	args->arg = **str;
}
*/
