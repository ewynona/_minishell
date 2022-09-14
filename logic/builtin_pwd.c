#include "../include/minishell.h"

int	builtin_pwd(void)
{
	char	*dir;

	dir = malloc(sizeof(char) * PATH_MAX);
	if (dir == NULL)
		return (print_error("pwd", strerror(errno), 2));
	dir = getcwd(dir, PATH_MAX);
	ft_putstr_fd(dir, 1);
	ft_putchar_fd('\n', 1);
	free(dir);
	return (0);
}
