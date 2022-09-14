#include "../include/minishell.h"

char	*full_path(char *path, char *cmd)
{
	char	*tmp;
	char	*cmd_path;

	tmp = ft_strjoin(path, "/");
	if (tmp == NULL)
	{
		g_exit_status = print_error("malloc", strerror(errno), 2);
		return (NULL);
	}
	cmd_path = ft_strjoin(tmp, cmd);
	if (cmd_path == NULL)
	{
		g_exit_status = print_error("malloc", strerror(errno), 2);
		free(tmp);
		return (NULL);
	}
	free(tmp);
	return (cmd_path);
}

char	*exictence_check(char *path, char *cmd)
{
	DIR				*ptr;
	struct dirent	*rdir;
	size_t			len;
	char			*cmd_path;

	ptr = opendir(path);
	rdir = readdir(ptr);
	len = ft_strlen(cmd);
	while (rdir)
	{
		if (!ft_strncmp(rdir->d_name, cmd, len) && rdir->d_name[len] == '\0')
		{
			cmd_path = full_path(path, cmd);
			if (cmd_path != NULL)
			{
				closedir(ptr);
				return (cmd_path);
			}
			else
				break ;
		}
		rdir = readdir(ptr);
	}
	closedir(ptr);
	return (NULL);
}

int	permission_check(char *cmd_path)
{
	struct stat	buf;

	if (lstat(cmd_path, &buf) == -1)
		g_exit_status = print_error(cmd_path, strerror(errno), 127);
	else if (S_ISDIR(buf.st_mode) == 1)
		g_exit_status = print_error(cmd_path, "is a directory", 126);
	else if ((buf.st_mode & S_IXUSR) != S_IXUSR)
		g_exit_status = print_error(cmd_path, "Permission denied", 126);
	return (g_exit_status);
}

char	*find_cmd_path(char *multi_path, char *cmd)
{
	char	**paths;
	char	*cmd_path;
	int		i;

	i = 0;
	paths = ft_split(multi_path, ':');
	if (paths == NULL)
	{
		g_exit_status = print_error("malloc", strerror(errno), 2);
		return (NULL);
	}
	while (paths[i])
	{
		cmd_path = exictence_check(paths[i], cmd);
		if (cmd_path)
			break ;
		i++;
	}
	if (cmd_path == NULL && g_exit_status != 2)
		g_exit_status = print_error(cmd, "command not found", 127);
	free_all(paths);
	return (cmd_path);
}

char	*cmd_proccessing(char *cmd, t_list *env)
{
	char	*multi_path;
	char	*cmd_path;

	g_exit_status = 0;
	multi_path = lst_get_value(env, "PATH");
	if (ft_strchr(cmd, '/') || cmd[0] == '.' || multi_path == NULL)
		cmd_path = ft_strdup(cmd);
	else
		cmd_path = find_cmd_path(multi_path, cmd);
	if (cmd_path == NULL)
		return (NULL);
	if (permission_check(cmd_path))
	{
		free(cmd_path);
		cmd_path = NULL;
	}
	return (cmd_path);
}
