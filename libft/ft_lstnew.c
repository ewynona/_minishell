/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsusanna <gsusanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 14:31:14 by asumerag          #+#    #+#             */
/*   Updated: 2021/04/14 19:34:02 by gsusanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(char *content)
{
	t_list	*p;

	p = (t_list *)malloc((sizeof(t_list)));
	if (!p)
		return (NULL);
	p->content = content;
	p->next = NULL;
	return (p);
}
