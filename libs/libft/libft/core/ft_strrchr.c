/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnelson <lnelson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 20:40:58 by napoleon          #+#    #+#             */
/*   Updated: 2021/09/11 07:42:11 by lnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*res;

	res = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			res = (char *)s + i;
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&(s[i]));
	return (res);
}
