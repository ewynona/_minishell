#include "../include/minishell.h"

int	pipe_me(int **fd, int p_count, t_cmd *cmd, t_list **env)
{
	int	*pid;
	int	i;
	int	status;

	pid = malloc(sizeof(int) * (p_count + 1));
	i = -1;
	while (++i <= p_count)
	{
		pid[i] = fork();
		if (pid[i] == 0)
		{
			dup_all(i, p_count, fd);
			g_exit_status = command_call(env, cmd);
			exit(g_exit_status);
		}
		else if (pid[i] == -1)
			exit(print_error("fork", strerror(errno), 2));
		cmd = cmd->next;
	}
	close_all(fd, p_count);
	i = -1;
	while (++i <= p_count)
		wait(&status);
	free(pid);
	return (status);
}

int	pipe_proc(t_list **env, t_cmd *cmd)
{
	int		p_count;
	int		status;
	int		**fd;

	p_count = pipe_count(cmd);
	fd = pipe_all(p_count);
	status = pipe_me(fd, p_count, cmd, env);
	if (status == 2 || status == 3)
		return (128 + status);
	return (WEXITSTATUS(status));
}
