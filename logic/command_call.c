#include "../include/minishell.h"

int	builtin_cmd(t_cmd *cmd, t_list **env)
{
	size_t	len;

	len = ft_strlen(cmd->cmd);
	if (!ft_strncmp("echo", cmd->cmd, len) && len >= 4)
		return (builtin_echo(cmd->arg));
	else if (!ft_strncmp("cd", cmd->cmd, len) && len >= 2)
		return (builtin_cd(cmd->arg[1], env));
	else if (!ft_strncmp("pwd", cmd->cmd, len) && len >= 3)
		return (builtin_pwd());
	else if (!ft_strncmp("export", cmd->cmd, len) && len >= 6)
		return (builtin_export(env, cmd->arg));
	else if (!ft_strncmp("unset", cmd->cmd, len) && len >= 5)
		return (builtin_unset(env, cmd->arg));
	else if (!ft_strncmp("env", cmd->cmd, len) && len >= 3)
		return (builtin_env(env));
	else if (!ft_strncmp("exit", cmd->cmd, len) && len >= 4)
		return (builtin_exit(cmd->arg));
	return (-1);
}

int	exec_cmd(t_list **env, t_cmd *cmd)
{
	char	**envp;
	int		status;
	pid_t	pid;

	envp = lst_to_env(*env);
	if (cmd->type != PIPE && !cmd->next)
	{
		pid = fork();
		if (pid == 0)
		{
			execve(cmd->cmd, cmd->arg, envp);
			exit(print_error("execve", strerror(errno), 1));
		}
		waitpid(pid, &status, 0);
	}
	else
	{
		execve(cmd->cmd, cmd->arg, envp);
		exit(print_error("execve", strerror(errno), 1));
	}
	free_all(envp);
	if (status == 2 || status == 3)
		return (128 + status);
	return (WEXITSTATUS(status));
}

int	command_ex(t_list **env, t_cmd *cmd)
{
	char	*tmp_cmd;

	if (cmd->cmd[0])
	{
		remove_key(env, "_");
		append_list_elem(env, "_", cmd->cmd);
		g_exit_status = builtin_cmd(cmd, env);
		if (g_exit_status != -1)
			return (g_exit_status);
		tmp_cmd = cmd->cmd;
		cmd->cmd = cmd_proccessing(cmd->cmd, *env);
		if (cmd->cmd)
			g_exit_status = exec_cmd(env, cmd);
		free(tmp_cmd);
	}
	return (g_exit_status);
}

int	command_call(t_list **env, t_cmd *cmd)
{
	int		fd_stdin;
	int		fd_stdout;

	if (cmd->cmd)
	{
		fd_stdin = dup(STDIN_FILENO);
		fd_stdout = dup(STDOUT_FILENO);
		if (cmd->fd_out > 2)
		{
			dup2(cmd->fd_out, 1);
			close(cmd->fd_out);
		}
		if (cmd->fd_in > 2)
		{
			dup2(cmd->fd_in, 0);
			close(cmd->fd_in);
		}
		if (ft_strncmp(">", cmd->cmd, 2))
			command_ex(env, cmd);
		dup2(fd_stdout, 1);
		dup2(fd_stdin, 0);
	}
	return (g_exit_status);
}
