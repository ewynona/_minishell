/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsusanna <gsusanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 17:24:00 by gsusanna          #+#    #+#             */
/*   Updated: 2021/04/10 16:18:36 by gsusanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	if (s == NULL || fd < 0)
		return ;
	i = 0;
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}
