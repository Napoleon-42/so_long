/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_charset.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnelson <lnelson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 19:16:48 by lnelson           #+#    #+#             */
/*   Updated: 2021/10/18 14:07:50 by lnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_str_is_charset(char *str, char *charset)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_strchr((const char *)charset, (int)str[i]) == NULL)
			return (0);
		i++;
	}
	return (1);
}
