/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnelson <lnelson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 14:04:34 by lnelson           #+#    #+#             */
/*   Updated: 2021/09/11 08:25:50 by lnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_count_word(char const *s1, char c)
{
	int	comp;
	int	cles;

	comp = 0;
	cles = 0;
	if (*s1 == '\0')
		return (0);
	while (*s1 != '\0')
	{
		if (*s1 == c)
			cles = 0;
		else if (cles == 0)
		{
			cles = 1;
			comp++;
		}
		s1++;
	}
	return (comp);
}

static int	ft_size_w(char const *str, int i, char c)
{
	int	j;

	j = 0;
	while (str[i] != c && str[i] != '\0')
	{
		i++;
		j++;
	}
	return (j);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		i;
	int		j;
	int		n_word;

	if (!s || !c)
		return (0);
	i = 0;
	n_word = 0;
	res = malloc(sizeof (char *) * (ft_count_word((char *)s, c) + 1));
	while (n_word != ft_count_word((char *)s, c))
	{
		while (s[i] && s[i] == c)
			i++;
		res[n_word] = malloc(sizeof(char) * (1 + ft_size_w(s, i, c)));
		j = 0;
		while (s[i] != c && s[i])
			res[n_word][j++] = s[i++];
		res[n_word][j] = 0;
		n_word++;
	}
	res[n_word] = 0;
	return (res);
}

/*

#This part can be used for preventig leaks in case of non allocation.
#Withdrawed due to norm v.3.

static char	**ft_free_abort(char **sstr, int nb)
{
	int	i;

	i = 0;
	while (i < nb)
	{
		free(sstr[nb]);
		i++;
	}
	free(sstr);
	return (0);
}

*/