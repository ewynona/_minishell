/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_utils1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsusanna <gsusanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 14:55:13 by gsusanna          #+#    #+#             */
/*   Updated: 2021/05/07 13:40:03 by gsusanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_ctrl_d(t_input *input)
{
	if (input->len != 0)
	{
		tputs(bell, 1, ft_putchar);
	}
	else
	{
		history_to_file(input);
		write(2, "exit\n", 5);
		exit (g_exit_status);
	}
}

int	ft_ctrl_c(t_input *input)
{
	g_exit_status = 1;
	ft_bzero(input->rest, ft_strlen(input->rest));
	write(1, "\n", 1);
	return (0);
}

void	ft_pressed_enter(t_input *input, int read_result, char *buf)
{
	input->rest = ft_strjoin_free(input->rest, buf);
	write(1, buf, read_result);
	input->len += read_result;
}
