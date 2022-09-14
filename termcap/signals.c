/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsusanna <gsusanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 13:03:36 by gsusanna          #+#    #+#             */
/*   Updated: 2021/05/07 17:21:08 by gsusanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	manage_signals(int key)
{
	if (key == 2)
		write(STDOUT_FILENO, "\n", 1);
	else if (key == 3)
		ft_putstr_fd("Quit: 3\n", 1);
}
