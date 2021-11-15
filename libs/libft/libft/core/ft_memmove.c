/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnelson <lnelson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 21:18:04 by napoleon          #+#    #+#             */
/*   Updated: 2021/09/11 07:27:29 by lnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*desti;
	unsigned char	*source;
	size_t			i;

	if (!dest && !src)
		return (NULL);
	i = 0;
	source = (unsigned char *)src;
	desti = (unsigned char *)dest;
	if (source < desti)
		while (++i <= n)
			desti[n - i] = source[n - i];
	else
		while (n-- > 0)
			*(desti++) = *(source++);
	return (dest);
}
