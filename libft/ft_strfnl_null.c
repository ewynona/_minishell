/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfnl_null.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsusanna <gsusanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 16:42:56 by gsusanna          #+#    #+#             */
/*   Updated: 2021/04/22 16:05:06 by gsusanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strfnl_null(char **str)
{
	int		i;
	char	*tmp;

	if (!str || *str == NULL)
		return (NULL);
	tmp = *str;
	i = 0;
	while (tmp[i] != '\0')
	{
		if (tmp[i] == '\n')
		{
			tmp[i] = '\0';
			return (tmp);
		}
		i++;
	}
	return (0);
}
