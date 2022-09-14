/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsusanna <gsusanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 10:04:38 by gsusanna          #+#    #+#             */
/*   Updated: 2021/04/10 16:30:00 by gsusanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_movecar(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r' || c == '\b');
}

int	ft_atoi(char *str)
{
	int				i;
	unsigned long	res;
	int				sign;

	i = 0;
	res = 0;
	sign = 1;
	while (ft_movecar(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		if (res > 9223372036854775807 && sign == -1)
			return (0);
		else if (res > 9223372036854775807 && sign == 1)
			return (-1);
		i++;
	}
	return ((int)res * sign);
}
