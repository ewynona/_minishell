/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsusanna <gsusanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 16:46:29 by gsusanna          #+#    #+#             */
/*   Updated: 2020/11/18 17:38:49 by gsusanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	x;
	unsigned char	*src;

	i = 0;
	x = (unsigned char)c;
	src = (unsigned char *)s;
	while (n--)
	{
		if (src[i] == x)
			return (&src[i]);
		i++;
	}
	return (NULL);
}
