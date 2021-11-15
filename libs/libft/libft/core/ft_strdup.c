/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnelson <lnelson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 19:30:28 by napoleon          #+#    #+#             */
/*   Updated: 2021/09/11 07:39:12 by lnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *c)
{
	char	*tmp;
	int		size;
	char	*res;

	size = 0;
	tmp = (char *)c;
	while (tmp[size])
		size++;
	res = malloc(sizeof(char) * (size + 1));
	size = 0;
	while (tmp[size])
	{
		res[size] = tmp[size];
		size++;
	}
	res[size] = 0;
	return (res);
}
