/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfnl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsusanna <gsusanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 16:42:56 by gsusanna          #+#    #+#             */
/*   Updated: 2021/04/22 15:05:16 by gsusanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strfnl(char *str)
{
	int	i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (str + i);
		i++;
	}
	return (0);
}
