/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdadd_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsusanna <gsusanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 19:35:28 by gsusanna          #+#    #+#             */
/*   Updated: 2021/04/24 12:12:51 by gsusanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdadd_front(t_dlist **lst, t_dlist *new)
{
	if (!new)
		return ;
	if (lst == NULL)
	{
		*lst = new;
		return ;
	}
	else
		(*lst)->previous = new;
	new->next = *lst;
	*lst = new;
}
