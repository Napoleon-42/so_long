/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnelson <lnelson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 18:40:00 by lnelson           #+#    #+#             */
/*   Updated: 2021/09/11 07:58:58 by lnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ptr;
	t_list	*res;

	if (!lst)
		return (NULL);
	(void)del;
	ptr = lst;
	res = ft_lstnew(f(ptr->content));
	while (ptr != 0)
	{
		if (res->content != 0)
			ft_lstadd_back(&res, ft_lstnew(f(ptr->content)));
		ptr = ptr->next;
	}
	return (res);
}
