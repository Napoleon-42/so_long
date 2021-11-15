/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnelson <lnelson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 21:02:14 by napoleon          #+#    #+#             */
/*   Updated: 2021/09/11 08:12:51 by lnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*result;
	size_t	i;

	i = 0;
	if (size == 0 || nmemb == 0)
		result = malloc(1);
	else
		result = malloc(size * nmemb);
	while (i <= nmemb * size)
	{
		((char *)result)[i] = 0;
		i++;
	}
	return (result);
}
