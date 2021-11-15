/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnelson <lnelson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 20:39:01 by napoleon          #+#    #+#             */
/*   Updated: 2021/09/11 07:40:45 by lnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_strnlen(char *str, unsigned int n)
{
	size_t	i;

	i = 0;
	while (str[i] && i < n)
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	size_t	i;
	size_t	dest_len;

	i = 0;
	dest_len = ft_strnlen(dest, size);
	if (size == 0)
		return (ft_strlen(src));
	if (size == dest_len)
		return (ft_strlen(src) + size);
	while (src[i] && ((dest_len + i) < (size - 1)))
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest_len + ft_strlen(src));
}
