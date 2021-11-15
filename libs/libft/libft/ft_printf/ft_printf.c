/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnelson <lnelson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 13:34:25 by lnelson           #+#    #+#             */
/*   Updated: 2021/09/11 08:14:27 by lnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include "printf.h"

int		print_percent(t_print args)
{
	if (args.wd > 0 && args.min == -1 && args.zer == -1)
		ft_putnchar_fd(' ', args.wd - 1, 1);
	if (args.wd > 0 && args.min == -1 && args.zer == 1)
		ft_putnchar_fd('0', args.wd - 1, 1);
	write(1, "%", 1);
	if (args.wd > 0 && args.min == 1)
		ft_putnchar_fd(' ', args.wd - 1, 1);
	return (args.wd > 0 ? args.wd : 1);
}

void	printf_param(const char **str, va_list *ap, int *res, t_print *args)
{
	init_print(args);
	get_param(str, ap, args);
	if (args->arg == 'c')
		*res += print_c((char)(va_arg(*ap, int)), args);
	if (args->arg == 's')
		*res += print_s((char *)(va_arg(*ap, int*)), args);
	if (args->arg == 'p')
		*res += print_p((uintmax_t)(va_arg(*ap, uintmax_t)), args);
	if (args->arg == 'd' || args->arg == 'i')
		*res += print_i_d((int)va_arg(*ap, int), args);
	if (args->arg == 'u')
		*res += print_u((unsigned int)va_arg(*ap, unsigned int), args);
	if (args->arg == '%')
		*res += print_percent(*args);
	if (args->arg == 'x' || args->arg == 'X')
		*res += print_x((unsigned int)va_arg(*ap, unsigned int), args);
	if (args->arg == 'n')
		*((int *)va_arg(*ap, int*)) = *res;
	if (args->arg == 'f')
		*res += print_f((double)va_arg(*ap, double), args);
}

int		ft_printf(const char *format, ...)
{
	int		res;
	va_list	ap;
	t_print args;

	va_start(ap, format);
	res = 0;
	while (*format != 0)
	{
		if (*format == '%')
			printf_param(&format, &ap, &res, &args);
		else
		{
			ft_putchar_fd(*format, 1);
			res++;
		}
		if (*format != 0)
			format++;
	}
	va_end(ap);
	return (res);
}


**int main()
**{
**	 ------------CHAR AND STRING TESTS----------------
**  ft_printf("\nc = |%1c%2c%3c|", '"', '!', '"');
**	ft_printf("\nc = |%3c|", 'A');
**    ft_printf("\nc = |%-3c|", 'A');
**    ft_printf("\nc = |%-*c|", 3,'A');
**
**	ft_printf("\ns = |%.7s|", "hello");
**	ft_printf("\ns = |%.2s%.7s|", "hello", "world");
**	ft_printf("\ns = |%.7s%.2s|", "hello", "world");
**	ft_printf("\ns = |%.5s%7s|", "yo", "boi");
**
**	printf("\n\nTrue printf:\ns = |%.7s|", "hello");
**	printf("\ns = |%.2s%.7s|", "hello", "world");
**	printf("\ns = |%.7s%.2s|", "hello", "world");
**	printf("\ns = |%.5s%7s|", "yo", "boi");
**
**	 ------------POINTER TESTS----------------
**	int a;
**
**	printf("\n\n p = -|%p|\n", &a);
**	ft_printf("\n p = +|%p|", &a);
**
**    printf("\n\n p = -|%20p|\n", &a);
**    ft_printf(" p = +|%20p|", &a);
**
**    printf("\n\n p = -|%20p|\n", &a);
**    ft_printf(" p = +|%020p|", &a);
**
**    printf("\n\n p = +|%-20p|\n", &a);
**    ft_printf(" p = -|%-20p|", &a);
**
**	------------ % TEST ----------------
**	ft_printf("%% = |% 0-33.*%|", 34);
**
**	 ------------ N TEST----------------
**	int b;
**
**	b = -35;
**	printf("before = %i\n", b);
**	ft_printf("0123456789%n\n", &b);
**	printf(" after = %i", b);
**
**	------------ INT TESTS----------------
**
**	ft_printf("\ni = |%i|", -2147483648);
**    ft_printf("\ni = |%0 15i|",  -2147483648);
**    ft_printf("\ni = |%0 -12i|", -2147483648);
**    ft_printf("\ni = |%0 -15.13i|", -2147483648);
**    ft_printf("\ni = |% -15.13i|", -2147483648);
**    ft_printf("\ni = |% 15.13i|", -2147483648);
**    ft_printf("\ni = |%015.13i|", -2147483648);
**    ft_printf("\ni = |%0*.9i|\n", 15, -2147483648);
**
**	------------ UNSIGNED INT TESTS----------------
**
**    ft_printf("\nu = |%015u|",  4294967295);
**    ft_printf("\nu = |%0-12u|", 4294967295);
**    ft_printf("\nu = |%0-15.13u|", 4294967295);
**    ft_printf("\nu = |%-15.13u|", 4294967295);
**    ft_printf("\nu = |%15.13u|", 4294967295);
**   ft_printf("\nu = |%015.13u|", 4294967295);
**    ft_printf("\nu = |%0 *.9u|\n", 15, 4294967295);
**
**	------------ XEXA TESTS----------------
**
**    ft_printf("\nx = |%7x|", (unsigned int)33);
**    ft_printf("\nx = |%5x|", (unsigned int)52625);
**    ft_printf("\nx = |%2x|", (unsigned int)94827);
**    ft_printf("\nx = |%-7x|", (unsigned int)33);
**    ft_printf("\nx = |%-5x|", (unsigned int)52625);
**    ft_printf("\nx = |%.5x|\n", (unsigned int)21);
**
**	----------- FLOAT TESTS----------------
**
**	ft_printf("\nf = |%f|", __FLT_MIN__);
**    ft_printf("\nf = |%0 15f|", __FLT_MIN__);
**	ft_printf("\nf = |% -12f|", __FLT_MIN__);
**    ft_printf("\nf = |% -15.13f|", __FLT_MIN__);
**    ft_printf("\nf = |% 15.13f|", __FLT_MIN__);
**    ft_printf("\nf = |%015.13f|", __FLT_MIN__);
**    ft_printf("\nf = |%0*.9f|\n", 15, __FLT_MIN__);
**	printf("%3.7i", -2375);
**	return 0;
**}
*/
