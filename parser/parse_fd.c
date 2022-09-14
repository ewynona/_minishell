#include "../include/minishell.h"

static char	*check_syntax(char *str, int *option)
{
	*option = 0;
	if (!ft_strncmp(">>", str, 2))
	{
		*option = O_APPEND;
		str += 2;
	}
	else if (*str == '>')
	{
		*option = O_TRUNC;
		str++;
	}
	else if (*str == '<')
		str++;
	while (*str == ' ')
		str++;
	return (str);
}

int	open_close_file(char *file, int option, t_cmd *cmd)
{
	int	fd;

	if (!option)
	{
		fd = open(file, O_RDONLY);
		if (fd == -1)
			return (print_error(file, strerror(errno), 1));
		if (cmd->fd_in)
			close(cmd->fd_in);
		cmd->fd_in = fd;
	}
	else
	{
		fd = open(file, O_WRONLY | O_CREAT | option, 00644);
		if (fd == -1)
			return (print_error(file, strerror(errno), 1));
		if (cmd->fd_out)
			close(cmd->fd_out);
		cmd->fd_out = fd;
	}
	return (0);
}

static char	*all_parse(char *command, char **new_str, t_list *env)
{
	command = ft_shielding(command, new_str, 0);
	command = single_quotes(command, new_str);
	if (!command)
		return (NULL);
	command = double_quotes(command, new_str, env);
	if (!command)
		return (NULL);
	command = parse_env(command, new_str, env);
	if (!command)
		return (NULL);
	command = add_chars(command, new_str, "\\\'\"$|><; ");
	if (*command == ' ')
	{
		while (*command == ' ')
			command++;
		if (!(ft_strchr("><|", *command)))
			*new_str = ft_strnjoin(*new_str, " ", 1);
	}
	return (command);
}

char	*parse_fd(char *str, t_cmd *cmd, t_list *env)
{
	int		option;
	char	*file;

	if (*str != '>' && *str != '<')
		return (str);
	option = 0;
	str = check_syntax(str, &option);
	file = ft_calloc(1, sizeof(char));
	while (!ft_strchr(">< |;", *str) && *str)
	{
		str = all_parse(str, &file, env);
		if (str == NULL)
		{
			free(file);
			return (NULL);
		}
	}
	if (open_close_file(file, option, cmd))
		str = NULL;
	free(file);
	return (str);
}
