/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsusanna <gsusanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 15:51:04 by asumerag          #+#    #+#             */
/*   Updated: 2021/04/27 15:23:18 by gsusanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*p;

	p = *lst;
	if (p != NULL)
	{
		while (p->next != NULL)
			p = p->next;
		p->next = new;
	}
	else
		*lst = new;
}
