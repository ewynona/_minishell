/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsusanna <gsusanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 20:40:44 by gsusanna          #+#    #+#             */
/*   Updated: 2021/05/07 13:03:11 by gsusanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	history_from_file(t_input *input)
{
	char	*address;
	char	*line;
	int		fd;

	address = getenv("HOME");
	address = ft_strjoin(address, "/.minishell_history.txt");
	fd = open(address, O_CREAT | O_RDONLY, S_IRWXU);
	if (fd == -1)
		ft_err("open failed on file");
	else
	{
		while (get_next_line(fd, &line) > 0)
			ft_lst_add_history(input->history, line);
		free(address);
		free(line);
		close(fd);
	}
}

void	history_to_file(t_input *input)
{
	char		*address;
	int			fd;

	address = getenv("HOME");
	address = ft_strjoin(address, "/.minishell_history.txt");
	fd = open(address, O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);
	input->history->pointer = input->history->root;
	while (input->history->pointer)
	{
		write(fd, input->history->pointer->content,
			ft_strlen(input->history->pointer->content));
		write(fd, "\n", 1);
		input->history->pointer = input->history->pointer->next;
	}
	free(address);
	close(fd);
}
