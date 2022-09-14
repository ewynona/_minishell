#include "../include/minishell.h"

char	*ft_path(char *arg, t_list *env)
{
	char	*path;
	char	*tmp;

	if (arg == NULL)
	{
		tmp = lst_get_value(env, "HOME");
		if (tmp == NULL)
		{
			g_exit_status = print_error("cd", "HOME not set", 1);
			return (NULL);
		}
		path = ft_strdup(tmp);
		if (path == NULL)
			g_exit_status = print_error("cd", strerror(errno), 2);
	}
	else
	{
		path = ft_strdup(arg);
		if (path == NULL)
			print_error("cd", strerror(errno), 1);
	}
	return (path);
}

int	builtin_cd(char *arg, t_list **env)
{
	char	*oldpwd;
	char	*pwd;
	char	dir[PATH_MAX];

	if (arg[0] == '\0')
		return (0);
	pwd = ft_path(arg, *env);
	if (pwd == NULL)
		return (g_exit_status);
	oldpwd = lst_get_value(*env, "PWD");
	if (chdir(pwd) == -1)
	{
		print_error(pwd, ": No such file or directory", 1);
		free(pwd);
		return (1);
	}
	free(pwd);
	getcwd(dir, PATH_MAX);
	if (change_or_append_str(env, "OLDPWD", oldpwd)
		|| change_or_append_str(env, "PWD", dir)
		|| change_or_append_str(env, "_", "cd"))
		return (2);
	return (0);
}
