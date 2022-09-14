/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsusanna <gsusanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 20:40:33 by gsusanna          #+#    #+#             */
/*   Updated: 2021/05/07 13:03:16 by gsusanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_dhistory	*ft_create_history(void)
{
	t_dhistory	*history;

	history = ft_calloc(1, sizeof(t_dhistory));
	if (history == NULL)
	{
		ft_err("Couldn't alocate memmory for history!");
	}
	history->root = NULL;
	history->pointer = NULL;
	return (history);
}

void	ft_lst_add_history(t_dhistory *history, char *str)
{
	t_dlist	*node;

	if (ft_strlen(str) > 0 && !is_empty_string(str))
	{
		node = ft_lstdnew(str);
		if (!node)
		{
			ft_err("SOME MEMMORY SHIT");
			return ;
		}
		ft_lstdadd_back(&history->root, node);
		history->pointer = NULL;
	}
	else
		return ;
}

char	*ft_history_up(t_dhistory *history)
{
	char	*result;

	result = NULL;
	if (history->pointer == NULL)
	{
		if (history->root != NULL)
		{
			history->pointer = history->root;
			while (history->pointer->next)
				history->pointer = history->pointer->next;
			result = (char *)history->pointer->content;
			return (result);
		}
		write(1, "\a", 1);
		return (NULL);
	}
	else
	{
		if (history->pointer->previous)
			history->pointer = history->pointer->previous;
		result = (char *)history->pointer->content;
	}
	return (result);
}

char	*ft_history_down(t_dhistory *history)
{
	char	*result;

	result = NULL;
	if (history->pointer == NULL)
	{
		write(1, "\a", 1);
		return (NULL);
	}
	else
	{
		history->pointer = history->pointer->next;
		if (history->pointer == NULL)
		{
			return (NULL);
		}
		else
			result = (char *)history->pointer->content;
	}
	return (result);
}
