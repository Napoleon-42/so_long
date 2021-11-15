/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnelson <lnelson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 15:27:43 by lnelson           #+#    #+#             */
/*   Updated: 2021/09/11 07:57:56 by lnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **begin_list, t_list *new)
{
	t_list	*ptr;

	if (*begin_list == 0)
		*begin_list = new;
	else
	{
		ptr = *begin_list;
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = new;
	}
}
