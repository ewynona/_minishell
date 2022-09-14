#include "../include/minishell.h"

int	pipe_count(t_cmd *cmd)
{
	int	i;

	i = 0;
	while (cmd->next)
	{
		cmd = cmd->next;
		i++;
	}
	return (i);
}

int	close_all(int **fd, int p_count)
{
	int	i;

	i = 0;
	while (i < p_count)
	{
		close(fd[i][0]);
		close(fd[i][1]);
		free(fd[i]);
		i++;
	}
	free(fd);
	return (0);
}

int	**pipe_all(int p_count)
{
	int	i;
	int	**fd;

	i = 0;
	fd = malloc(sizeof(int *) * p_count);
	while (i < p_count)
	{
		fd[i] = malloc(sizeof(int) * 2);
		pipe(fd[i]);
		i++;
	}
	return (fd);
}

void	dup_all(int i, int p_count, int **fd)
{
	if (i != 0)
		dup2(fd[i - 1][0], 0);
	if (i != p_count)
		dup2(fd[i][1], 1);
	close_all(fd, p_count);
}
