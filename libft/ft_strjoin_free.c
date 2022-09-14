/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsusanna <gsusanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 18:26:43 by gsusanna          #+#    #+#             */
/*   Updated: 2021/04/24 15:57:58 by gsusanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char *s1, char const *s2)
{
	char	*joined;
	size_t	joinedlen;
	size_t	i;

	i = 0;
	if (!s2)
		return (s1);
	joinedlen = ft_strlen(s1) + ft_strlen(s2);
	joined = (char *)malloc(sizeof(char) * (joinedlen + 1));
	if (!joined)
		return (s1);
	while (s1 && s1[i] != '\0')
	{
		joined[i] = s1[i];
		i++;
	}
	while (*s2)
	{
		joined[i] = *s2++;
		i++;
	}
	joined[i] = '\0';
	free(s1);
	return (joined);
}
