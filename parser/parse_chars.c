#include "../include/minishell.h"

char	*add_chars(char *str, char **cmd_arg, char *stop_symbols)
{
	int		i;
	char	*tmp;

	i = 0;
	if (ft_strchr(stop_symbols, str[i]))
		return (str);
	while (!ft_strchr(stop_symbols, str[i]) && str[i])
		i++;
	tmp = ft_calloc(i + 1, sizeof(char));
	i = 0;
	while (!ft_strchr(stop_symbols, str[i]) && str[i])
	{
		tmp[i] = str[i];
		i++;
	}
	*cmd_arg = ft_strjoin_free(*cmd_arg, tmp);
	free(tmp);
	return (&str[i]);
}

char	*ft_shielding(char *str, char **cmd_arg, int type)
{
	if (*str == '\\')
	{
		if ((ft_strchr("\\\"$", *(str + 1)) && type == '\"') || !type)
		{
			str++;
			*cmd_arg = ft_strnjoin(*cmd_arg, str, 1);
			if (*cmd_arg == NULL)
			{
				g_exit_status = print_error(str, strerror(errno), 2);
				return (NULL);
			}
			str++;
		}
		else
		{
			*cmd_arg = ft_strnjoin(*cmd_arg, str, 2);
			if (*cmd_arg == NULL)
			{
				g_exit_status = print_error(str, strerror(errno), 2);
				return (NULL);
			}
			str += 2;
		}
	}
	return (str);
}
