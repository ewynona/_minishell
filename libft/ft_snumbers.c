/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_snumbers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsusanna <gsusanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 14:23:41 by gsusanna          #+#    #+#             */
/*   Updated: 2021/03/13 14:24:38 by gsusanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_snumbers(char *str)
{
	while (*str >= '0' && *str <= '9')
	{
		if (*str == '\0')
			break ;
		str++;
	}
	return (str);
}
