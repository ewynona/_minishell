/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsusanna <gsusanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 13:48:51 by gsusanna          #+#    #+#             */
/*   Updated: 2021/05/07 15:30:01 by gsusanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	input_put_str(t_input *input, char *str)
{
	tputs(restore_cursor, 1, ft_putchar);
	tputs(clr_eos, 1, ft_putchar);
	free(input->rest);
	input->rest = ft_strdup(str);
	ft_putstr_fd(str, 1);
	input->len = ft_strlen(str);
}

void	ft_key_up(t_input *input)
{
	char	*line;

	if (input->h_flag == 0)
		input->save_line = ft_strdup(input->rest);
	line = ft_history_up(input->history);
	if (line != NULL)
	{
		input->h_flag = 1;
		input_put_str(input, line);
	}
}

void	ft_key_down(t_input *input)
{
	char	*line;

	line = ft_history_down(input->history);
	if (input->h_flag == 1)
	{
		if (line == NULL)
		{
			input->h_flag = 0;
			line = input->save_line;
			input_put_str(input, line);
		}
		else
			input_put_str(input, line);
	}
}

void	ft_key_backspace(t_input *input)
{
	int	i;

	if (ft_strlen(input->rest) > 0)
	{
		i = 0;
		tputs(cursor_left, 1, ft_putchar);
		tputs(delete_character, 1, ft_putchar);
		while (input->rest[i] != '\0')
			i++;
		input->rest[i - 1] = '\0';
		input->len--;
	}
}

int	ft_pressed_key(char *str, t_input *input)
{
	if (!ft_strncmp(str, "\177", 4) || !ft_strncmp(str, key_backspace, 4)
		|| *str == '\b')
		ft_key_backspace(input);
	else if (!ft_strncmp(str, "\4", 4))
		ft_ctrl_d(input);
	else if (!ft_strncmp(str, key_up, 3) || !ft_strncmp(str, "\e[A", 3))
		ft_key_up(input);
	else if (!ft_strncmp(str, key_down, 3) || !ft_strncmp(str, "\e[B", 3))
		ft_key_down(input);
	else if (!ft_strncmp(str, key_right, 3) || !ft_strncmp(str, key_left, 3)
		|| !ft_strncmp(str, "\e[C", 3) || !ft_strncmp(str, "\e[D", 3))
		tputs(bell, 1, ft_putchar);
	else if (!ft_strncmp(str, key_end, 3) || !ft_strncmp(str, key_home, 3))
		tputs(bell, 1, ft_putchar);
	else if (ft_is_not_printable(*str))
		tputs(bell, 1, ft_putchar);
	else
		return (0);
	return (1);
}
