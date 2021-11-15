/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnelson <lnelson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 13:56:22 by lnelson           #+#    #+#             */
/*   Updated: 2021/09/11 07:29:47 by lnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnstr_fd(char *str, int n, int fd)
{
	int	i;

	if (n < 0)
	{
		ft_putstr_fd(str, fd);
		return ;
	}
	i = 0;
	while (i < n && str[i] != 0)
	{
		ft_putchar_fd(str[i], fd);
		i++;
	}
}
