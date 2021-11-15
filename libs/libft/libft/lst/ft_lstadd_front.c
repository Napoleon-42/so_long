/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnelson <lnelson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 14:36:38 by lnelson           #+#    #+#             */
/*   Updated: 2021/09/11 07:58:05 by lnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **begin_list, t_list *new)
{
	if (*begin_list == 0)
		*begin_list = new;
	else
	{
		new->next = *begin_list;
		*begin_list = new;
	}
}
