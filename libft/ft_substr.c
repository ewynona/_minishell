/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsusanna <gsusanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 16:04:12 by gsusanna          #+#    #+#             */
/*   Updated: 2021/04/10 16:13:55 by gsusanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	slen;
	size_t	i;
	char	*substr;

	i = 0;
	if (s == NULL)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen)
	{
		substr = (char *)malloc(sizeof(char));
		substr[0] = '\0';
		return (substr);
	}
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	while (i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
