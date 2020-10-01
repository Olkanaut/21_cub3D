/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshang <bshang@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 11:34:07 by bshang            #+#    #+#             */
/*   Updated: 2020/05/22 17:13:49 by bshang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*current;
	t_list	*res;

	if (!lst || !f || !del)
		return (NULL);
	res = NULL;
	while (lst)
	{
		if (!(current = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&res, del);
			return (NULL);
		}
		ft_lstadd_back(&res, current);
		lst = lst->next;
	}
	return (res);
}
