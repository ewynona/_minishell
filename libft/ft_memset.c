/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsusanna <gsusanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 09:11:51 by gsusanna          #+#    #+#             */
/*   Updated: 2021/04/10 16:26:25 by gsusanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	ch;

	ch = (unsigned char)c;
	i = 0;
	while (i < len)
	{
		((unsigned char *)b)[i] = ch;
		i++;
	}
	return (b);
}
