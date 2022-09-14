/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdadd_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsusanna <gsusanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 15:43:27 by gsusanna          #+#    #+#             */
/*   Updated: 2021/04/27 12:21:36 by gsusanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdadd_back(t_dlist **lst, t_dlist *new)
{
	t_dlist	*p;

	p = *lst;
	if (p != NULL)
	{
		while (p->next != NULL)
			p = p->next;
		new->previous = p;
		p->next = new;
	}
	else
		*lst = new;
}
