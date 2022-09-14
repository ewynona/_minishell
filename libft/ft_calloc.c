/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsusanna <gsusanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 01:54:50 by gsusanna          #+#    #+#             */
/*   Updated: 2020/11/24 12:38:36 by gsusanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t			i;
	unsigned char	*res;

	i = 0;
	size *= count;
	res = (unsigned char *)malloc(size);
	if (!res)
		return (NULL);
	while (i < size)
		res[i++] = 0;
	return ((void *)res);
}
