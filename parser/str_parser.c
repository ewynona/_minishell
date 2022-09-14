#include "../include/minishell.h"

char	*space_proc(char *str, t_list **lst)
{
	t_list	*tmp;

	tmp = *lst;
	if (*str == ' ')
	{
		while (*str == ' ')
			str++;
		if (!ft_strchr("><;|", *str) && *str != '\0'
			&& tmp->content[0] != '\0')
		{
			ft_lstadd_back(lst, ft_lstnew(ft_strdup("")));
			*lst = tmp->next;
		}
	}
	return (str);
}

static char	*all_parse(char *str, t_list **lst, t_list *env, t_cmd *cmd)
{
	t_list	*tmp;

	tmp = *lst;
	str = ft_shielding(str, &tmp->content, 0);
	str = single_quotes(str, &tmp->content);
	if (!str)
		return (NULL);
	str = double_quotes(str, &tmp->content, env);
	if (!str)
		return (NULL);
	str = parse_env(str, &tmp->content, env);
	str = parse_fd(str, cmd, env);
	if (!str)
		return (NULL);
	str = add_chars(str, &tmp->content, "\\\'\"$|><; ");
	str = space_proc(str, lst);
	return (str);
}

char	*pipe_add(char *str, t_list **tmp, t_list **lst, t_cmd **cmd)
{
	t_cmd	*cmd_tmp;

	cmd_tmp = *cmd;
	if (*str == PIPE)
	{
		str++;
		while (*str == ' ')
			str++;
		cmd_get_arg(*lst, *cmd);
		free_lst(*lst);
		*lst = ft_lstnew(ft_strdup(""));
		*tmp = *lst;
		cmd_add_back(cmd, cmd_init(PIPE));
		*cmd = cmd_tmp->next;
	}
	return (str);
}

char	*command_pars(char *str, t_list *env, t_list *lst, t_cmd *cmd)
{
	t_list	*tmp;

	tmp = lst;
	while (*str)
	{
		str = all_parse(str, &tmp, env, cmd);
		if (str == NULL)
		{
			free_lst(lst);
			return (NULL);
		}
		str = pipe_add(str, &tmp, &lst, &cmd);
		if (*str == ';')
		{
			cmd_get_arg(lst, cmd);
			free_lst(lst);
			return (str + 1);
		}
	}
	cmd_get_arg(lst, cmd);
	free_lst(lst);
	return (NULL);
}

void	ft_parse(char *str, t_list **env)
{
	char	*tmp;
	t_cmd	*cmd;
	t_list	*lst;

	tmp = str;
	term_init(0);
	if (str == NULL)
		return ;
	if (str_check(str))
		return ;
	while (str)
	{
		cmd = cmd_init(0);
		lst = ft_lstnew(ft_strdup(""));
		str = command_pars(str, *env, lst, cmd);
		if (cmd->cmd)
		{
			if (cmd->next)
				g_exit_status = pipe_proc(env, cmd);
			else
				g_exit_status = command_call(env, cmd);
		}
		cmd_free(&cmd);
	}
	free(tmp);
}
