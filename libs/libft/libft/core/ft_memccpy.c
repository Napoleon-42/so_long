/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnelson <lnelson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 19:58:30 by napoleon          #+#    #+#             */
/*   Updated: 2021/09/11 07:26:41 by lnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*desti;
	unsigned char	*source;

	desti = (unsigned char *)dest;
	source = (unsigned char *)src;
	while (n > 0)
	{
		*desti++ = *source++;
		if (*source == (unsigned char)c)
		{
			*desti = *source;
			return (desti + 1);
		}
		n--;
	}
	return (NULL);
}
