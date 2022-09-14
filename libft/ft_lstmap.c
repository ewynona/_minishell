/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsusanna <gsusanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 17:36:02 by asumerag          #+#    #+#             */
/*   Updated: 2021/05/07 12:35:14 by gsusanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lstlist;
	t_list	*new;

	lstlist = NULL;
	new = NULL;
	if (!lst)
		return (NULL);
	while (lst)
	{
		new = ft_lstnew(f(lst->content));
		if (!new)
			ft_lstclear(&lstlist, del);
		ft_lstadd_back(&lstlist, new);
		lst = lst->next;
	}
	return (lstlist);
}
