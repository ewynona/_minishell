/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsusanna <gsusanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 23:47:48 by gsusanna          #+#    #+#             */
/*   Updated: 2021/04/10 16:14:01 by gsusanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	size_t	i;
	size_t	k;
	char	*trimed;

	if (s1 == NULL || set == NULL)
		return (NULL);
	i = 0;
	while (s1[i] && (ft_strchr(set, s1[i]) != NULL))
		i++;
	len = ft_strlen(s1);
	while (len > i && (ft_strchr(set, s1[len - 1]) != NULL))
		len--;
	trimed = (char *)malloc(sizeof(*s1) * (len - i + 1));
	if (!trimed)
		return (NULL);
	k = 0;
	while (i < len)
	{
		trimed[k] = s1[i];
		k++;
		i++;
	}
	trimed[k] = '\0';
	return (trimed);
}
