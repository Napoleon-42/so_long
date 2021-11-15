/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnelson <lnelson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 20:10:07 by napoleon          #+#    #+#             */
/*   Updated: 2021/09/11 07:27:45 by lnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*tmp;

	if (n == 0)
		return (s);
	tmp = (unsigned char *)s;
	while (n-- > 0)
	{
		*tmp = (unsigned char)c;
		tmp++;
	}
	return (s);
}
