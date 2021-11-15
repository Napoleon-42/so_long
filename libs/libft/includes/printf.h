/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnelson <lnelson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 13:32:12 by lnelson           #+#    #+#             */
/*   Updated: 2021/09/11 08:07:40 by lnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# define LOW_HEXA "0123456789abcdef"
# define UPP_HEXA "0123456789ABCDEF"

typedef struct s_print
{
	char	zer;
	char	min;
	int		sz;
	int		wd;
	int		prc;
	char	arg;
	char	spc;
	char	pls;
	char	ash;
}				t_print;

int				ft_printf(const char *format, ...);

void			init_print(t_print *args);
void			get_param(const char **str, va_list *ap, t_print *args);

int				print_c(char c, t_print *args);
int				print_s(char *str, t_print *args);
int				print_p(uintmax_t nbr, t_print *args);
int				print_i_d(int nbr, t_print *args);
int				print_u(unsigned int nbr, t_print *args);
int				print_x(unsigned int nbr, t_print *args);
int				print_f(double nbr, t_print *args);
void			print_flag_utils(t_print *args, int nbr);

#endif
