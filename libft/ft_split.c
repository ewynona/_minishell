/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsusanna <gsusanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 19:01:44 by gsusanna          #+#    #+#             */
/*   Updated: 2021/04/10 16:24:45 by gsusanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_wordcount(const char *s, char c)
{
	size_t		word_count;
	int			i;

	word_count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != c && s[i] != '\0')
		{
			word_count++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
	}
	return (word_count);
}

static size_t	ft_wordlen(const char *s, char c)
{
	size_t		len;

	len = 0;
	while (s[len] != c && s[len] != '\0')
		len++;
	return (len);
}

static char	**ft_wipe(char **res, size_t word_index)
{
	size_t		i;

	i = 0;
	while (i < word_index)
	{
		free(res[i]);
		res[i] = NULL;
		i++;
	}
	free(res);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char		**res;
	size_t		word_index;
	size_t		i;

	if (s == NULL)
		return (NULL);
	res = ft_calloc((ft_wordcount(s, c) + 1), sizeof(char *));
	if (!res)
		return (NULL);
	word_index = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != c && s[i] != '\0')
		{
			res[word_index] = ft_substr(s, i, ft_wordlen(&s[i], c));
			if (!res[word_index])
				return (ft_wipe(res, word_index));
			i += ft_wordlen(&s[i], c);
			word_index++;
		}
	}
	return (res);
}
