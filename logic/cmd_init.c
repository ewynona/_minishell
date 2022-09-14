#include "../include/minishell.h"

t_cmd	*cmd_init(int type)
{
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd));
	cmd->next = NULL;
	cmd->arg = NULL;
	cmd->cmd = NULL;
	cmd->fd_in = 0;
	cmd->fd_out = 0;
	cmd->type = type;
	return (cmd);
}

void	cmd_add_back(t_cmd **cmd, t_cmd *new_cmd)
{
	t_cmd	*tmp;

	tmp = *cmd;
	if (tmp != NULL)
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new_cmd;
	}
	else
		*cmd = new_cmd;
}

void	cmd_get_arg(t_list *lst, t_cmd *cmd)
{
	int	i;

	i = 0;
	while (cmd->next)
		cmd = cmd->next;
	cmd->cmd = ft_strdup(lst->content);
	cmd->arg = ft_calloc(ft_lstsize(lst) + 1, sizeof(char *));
	while (lst)
	{
		cmd->arg[i] = ft_strdup(lst->content);
		i++;
		lst = lst->next;
	}
}

void	cmd_free(t_cmd **cmd)
{
	t_cmd	*tmp;
	t_cmd	*tmp2;

	tmp = *cmd;
	while (tmp)
	{
		tmp2 = tmp;
		tmp = tmp->next;
		if (tmp2->fd_in)
			close(tmp2->fd_in);
		tmp2->fd_in = 0;
		if (tmp2->fd_out)
			close(tmp2->fd_out);
		tmp2->fd_out = 0;
		free_all(tmp2->arg);
		free(tmp2->cmd);
		free(tmp2);
	}
}
