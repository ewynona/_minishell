/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsusanna <gsusanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 01:29:41 by gsusanna          #+#    #+#             */
/*   Updated: 2020/11/18 21:59:32 by gsusanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*res;
	size_t	len;

	len = ft_strlen(s);
	if ((char)c == '\0')
		return ((char *)s + len);
	res = (char *)s + len;
	while (res >= s)
	{
		if (*res == (char)c)
			return (res);
		res--;
	}
	return (NULL);
}
