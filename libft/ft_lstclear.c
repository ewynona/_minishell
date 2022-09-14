/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asumerag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 15:38:50 by asumerag          #+#    #+#             */
/*   Updated: 2021/04/14 15:17:04 by asumerag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;
	t_list	*tmp1;

	tmp = *lst;
	while (tmp)
	{
		tmp1 = tmp;
		tmp = tmp->next;
		(*del)(tmp1->content);
		free(tmp1);
	}
	*lst = NULL;
}
