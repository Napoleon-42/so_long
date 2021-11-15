/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnelson <lnelson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 19:42:12 by napoleon          #+#    #+#             */
/*   Updated: 2019/11/29 19:11:25 by lnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	int		j;
	int		little_len;

	if (*little == 0)
		return ((char *)big);
	if (len == 0)
		return (NULL);
	little_len = 0;
	while (little[little_len])
		little_len++;
	i = 0;
	while (big[i] && i <= len - little_len)
	{
		j = 0;
		if (big[i] == *little && i <= len - little_len)
		{
			while ((big[i + j] == little[j]) && (big[i + j]))
				j++;
			if (little[j] == 0)
				return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}
