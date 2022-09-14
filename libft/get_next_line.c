/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsusanna <gsusanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 12:32:15 by gsusanna          #+#    #+#             */
/*   Updated: 2021/05/07 12:32:53 by gsusanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strjoin_null(char *s1, char *s2)
{
	size_t	i;
	size_t	len1;
	size_t	len2;
	char	*str;

	i = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = malloc(sizeof(char) * (len1 + len2) + 1);
	while (i < len1)
	{
		str[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < len2)
	{
		str[i + len1] = s2[i];
		i++;
	}
	str[len1 + len2] = '\0';
	if (s1)
		free(s1);
	return (str);
}

static int	end_line(const char *s)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i] != '\n' && s[i] != '\0')
			i++;
		if (s[i] == '\n')
			return (0);
	}
	return (1);
}

static char	*new_str(char *s)
{
	char	*str;
	size_t	i;

	i = 0;
	str = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!str)
		return (NULL);
	while (s[i] != '\n' && s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char	*next_str(char *s)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\n' && s[i])
		i++;
	if (s[i] == '\0')
	{
		free(s);
		return (NULL);
	}
	str = calloc(sizeof(char), (ft_strlen(s) - i) + 1);
	if (!(str))
	{
		free(s);
		return (NULL);
	}
	while (s[i + 1])
		str[j++] = s[1 + i++];
	free(s);
	return (str);
}

int	get_next_line(int fd, char **line)
{
	char		*buff;
	static char	*input;
	int			bts_read;

	bts_read = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || !(line)
		|| !(buff = malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (-1);
	while (end_line(input) && bts_read)
	{
		bts_read = read(fd, buff, BUFFER_SIZE);
		if (bts_read < 0)
		{
			free(buff);
			return (-1);
		}
		buff[bts_read] = '\0';
		input = ft_strjoin_null(input, buff);
	}
	free(buff);
	*line = new_str(input);
	input = next_str(input);
	if (bts_read == 0 || !(*line) || !input)
		return (0);
	return (1);
}
