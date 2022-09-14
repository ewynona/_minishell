/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_input_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsusanna <gsusanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 19:35:46 by gsusanna          #+#    #+#             */
/*   Updated: 2021/05/07 13:43:42 by gsusanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// void	ft_print_all(t_dlist *list)
// {
// 	int i
// 	 = 0;
// 	printf("\n");
// 	while (list)
// 	{
// 		printf("list%d -> %s\n", i++,  list->content);
// 		list = list->next;
// 	}
// }

int	is_empty_string(char *line)
{
	while (*line)
	{
		if (*line != ' ')
			return (0);
		line++;
	}
	return (1);
}

void	ft_main_struct_prep(t_input *input)
{
	input->len = 0;
	free(input->rest);
	input->rest = NULL;
}

int	get_next_input_line(t_input *input, t_list **env)
{
	int			read_result;
	char		buf[BUFFER_SIZE + 1];

	ft_main_struct_prep(input);
	ft_bzero(buf, (BUFFER_SIZE + 1) * sizeof(char));
	while (42)
	{
		read_result = read(STDIN_FILENO, buf, BUFFER_SIZE);
		buf[read_result] = 0;
		if (read_result == -1)
			ft_err("READ PROBLEM!");
		if (read_result == 0)
			return (0);
		else if (!ft_strncmp(buf, "\3", 3))
			return (ft_ctrl_c(input));
		if (ft_pressed_key(buf, input))
			continue ;
		else if (ft_strncmp(buf, "\n", 1))
			ft_pressed_enter(input, read_result, buf);
		else
			break ;
	}
	ft_lst_add_history(input->history, ft_strdup(input->rest));
	ft_parse(ft_strdup(input->rest), env);
	return (0);
}
