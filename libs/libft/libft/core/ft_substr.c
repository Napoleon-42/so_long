/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnelson <lnelson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 17:59:11 by napoleon          #+#    #+#             */
/*   Updated: 2021/09/11 07:42:59 by lnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;

	if (!s)
		return (0);
	if (ft_strlen(s) < (int)start)
		return (ft_strdup(""));
	i = 0;
	res = malloc((len + 1) * sizeof(char));
	while (i < len)
	{
		res[i] = s[start + i];
		i++;
	}
	res[len] = 0;
	return (res);
}
