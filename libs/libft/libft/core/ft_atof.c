/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnelson <lnelson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 15:10:24 by lnelson           #+#    #+#             */
/*   Updated: 2021/09/11 07:12:33 by lnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_atof_numeral(char *temp, double *numeral)
{
	if (*temp == '.' && *temp != 0)
	{
		temp++;
		while (*temp >= 48 && *temp <= 57 && *temp != 0)
			temp++;
		temp--;
		while (*temp >= 48 && *temp <= 57 && *temp != '.')
		{
			*numeral = *numeral / 10 + ((int)*temp - 48);
			temp--;
		}
		*numeral = *numeral / 10;
	}
}

double	ft_atof(const char *string)
{
	double	decimal;
	double	numeral;
	char	*temp;
	double	sign;

	sign = 1;
	decimal = 0.0000000000;
	numeral = 0.0000000000;
	temp = (char *)string;
	while (*temp && (*temp == ' ' || (*temp >= 7 && *temp <= 13 && *temp != 0)))
		temp++;
	if (*temp == '-' && *temp != 0)
		sign = -1;
	if (*temp == 45 || (*temp == 43 && *temp != 0))
		temp++;
	while (*temp >= 48 && *temp <= 57 && *temp != 0)
	{
		decimal = (decimal * 10) + ((int)*temp - 48);
		temp++;
	}
	if (*temp == '.')
		ft_atof_numeral(temp, &numeral);
	return ((decimal + numeral) * sign);
}
