/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsusanna <gsusanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 19:30:09 by gsusanna          #+#    #+#             */
/*   Updated: 2021/04/15 16:10:21 by gsusanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist	*ft_lstdnew(char *content)
{
	t_dlist	*p;

	p = (t_dlist *)malloc((sizeof(t_dlist)));
	if (!p)
		return (NULL);
	p->content = content;
	p->next = NULL;
	p->previous = NULL;
	return (p);
}
