/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnelson <lnelson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 14:02:56 by napoleon          #+#    #+#             */
/*   Updated: 2021/09/11 08:09:42 by lnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*itoa_brain(long int num, char *str, int str_size, long long *nb)
{
	int	i;

	i = str_size - 1;
	str[str_size] = 0;
	if (num < 0)
	{
		*nb = -num;
		str[0] = '-';
		while (i > 0)
		{
			str[i] = (*nb % 10) + 48;
			i--;
			*nb = *nb / 10;
		}
	}
	else
	{
		while (i >= 0)
		{
			str[i] = (num % 10) + 48;
			i--;
			num = num / 10;
		}
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char		*res;
	int			size;
	long int	temp;
	long long	nb;

	temp = n;
	size = 1;
	if (n < 0)
	{
		size++;
		temp = -temp;
	}
	while (temp >= 10)
	{
		size++;
		temp = temp / 10;
	}
	res = malloc((1 + size) * sizeof(char));
	itoa_brain((long int)n, res, size, &nb);
	return (res);
}
