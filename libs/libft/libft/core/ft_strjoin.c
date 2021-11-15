/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnelson <lnelson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 14:22:25 by lnelson           #+#    #+#             */
/*   Updated: 2021/09/11 07:40:22 by lnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	get_all_sizes(char const *s1, char const *s2, int *res)
{
	int	i;

	res[0] = 0;
	res[1] = 0;
	i = 0;
	while (s1[i])
	{
		res[0]++;
		res[1]++;
		i++;
	}
	i = 0;
	while (s2[i])
	{
		res[1]++;
		i++;
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		sizes[2];
	char	*res;

	if (!s1 || !s2)
		return (0);
	i = 0;
	get_all_sizes(s1, s2, sizes);
	res = malloc((sizes[1] + 1) * sizeof(char));
	res[sizes[1]] = 0;
	while (i < sizes[1])
	{
		if (i < sizes[0])
			res[i] = s1[i];
		else
			res[i] = s2[i - sizes[0]];
		i++;
	}
	return (res);
}
