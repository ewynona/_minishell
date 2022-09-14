/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsusanna <gsusanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 01:29:35 by gsusanna          #+#    #+#             */
/*   Updated: 2020/11/24 13:09:39 by gsusanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	h;
	char	*str;
	int		i;

	i = 0;
	h = (char)c;
	str = (char *)s;
	while (str[i] != '\0')
	{
		if (str[i] == h)
			return (&str[i]);
		i++;
	}
	if (str[i] == 0 && c == 0)
		return (&str[i]);
	return (0);
}
