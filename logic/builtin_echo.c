#include "../include/minishell.h"

int	builtin_echo(char **arg)
{
	int	i;
	int	new_line;

	i = 1;
	new_line = 0;
	if (arg[i])
	{
		if (!ft_strncmp(arg[i], "-n", 3))
		{
			new_line = 1;
			i++;
		}
		while (arg[i])
		{
			ft_putstr_fd(arg[i], 1);
			if (arg[i + 1] != NULL)
				ft_putchar_fd(' ', 1);
			i++;
		}
	}
	if (new_line != 1)
		ft_putchar_fd('\n', 1);
	return (0);
}
