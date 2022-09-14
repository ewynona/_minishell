/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstd_list_free.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsusanna <gsusanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 14:44:50 by gsusanna          #+#    #+#             */
/*   Updated: 2021/05/07 12:33:55 by gsusanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstd_list_free(t_dlist **root)
{
	t_dlist	*tmp;
	t_dlist	*tmp1;

	tmp = *root;
	while (tmp)
	{
		tmp1 = tmp;
		tmp = tmp->next;
		free(tmp1->content);
		free(tmp1);
	}
	*root = NULL;
}
