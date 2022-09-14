#include "../include/minishell.h"

int	check_num(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-')
			i++;
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	status_proc(char *numbers)
{
	int	num;

	num = ft_atoi(numbers);
	num %= 256;
	return (num);
}

int	builtin_exit(char **arg)
{
	if (arg != NULL)
	{
		if (arg[1] && check_num(arg[1]))
		{
			ft_putstr_fd("minishell: exit: ", 2);
			ft_putstr_fd(arg[1], 2);
			ft_putstr_fd(" numeric argument required\n", 2);
			g_exit_status = 255;
		}
		else if (arg[1])
		{
			if (arg[2] != NULL)
			{
				ft_putstr_fd("minishell: exit: too many arguments\n", 2);
				return (1);
			}
			else
				g_exit_status = status_proc(arg[1]);
		}
	}
	ft_putstr_fd("exit\n", 2);
	exit (g_exit_status);
}
