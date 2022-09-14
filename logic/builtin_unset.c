#include "../include/minishell.h"

static int	ft_check_arg(char *arg)
{
	int	i;

	i = 0;
	if (!(ft_isalpha(arg[0]) || arg[0] == '_'))
		return (1);
	while (arg[i])
	{
		if (!(ft_isalnum(arg[i]) || arg[i] == '_'))
			return (1);
		i++;
	}
	return (0);
}

int	builtin_unset(t_list **lst, char **arg)
{
	int		i;

	i = 0;
	g_exit_status = 0;
	while (arg[i])
	{
		if (ft_check_arg(arg[i]))
		{
			print_error(arg[i], ": not a valid identifier", 1);
			g_exit_status = 1;
			i++;
			continue ;
		}
		remove_key(lst, arg[i]);
		i++;
	}
	return (g_exit_status);
}
