/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsusanna <gsusanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 23:28:04 by gsusanna          #+#    #+#             */
/*   Updated: 2021/04/10 16:15:01 by gsusanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	src_len;
	size_t	dst_len;

	i = 0;
	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	j = dst_len;
	if (size <= dst_len)
		return (src_len + size);
	while (src[i] != '\0' && (i + j) < (size - 1))
	{
		dst[j + i] = src[i];
		i++;
	}
	dst[j + i] = '\0';
	return (dst_len + src_len);
}
