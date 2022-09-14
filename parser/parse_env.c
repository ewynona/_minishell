#include "../include/minishell.h"

char	*find_key(char *str)
{
	char	*key;
	int		i;

	i = 0;
	while (ft_isalnum(str[i]) || str[i] == '_')
		i++;
	key = ft_substr(str, 0, i);
	return (key);
}

char	*env_put(char *str, char **cmd_arg, t_list *env)
{
	char	*key;
	char	*value;

	if (*str >= '0' && *str <= '9')
	{
		*cmd_arg = ft_strnjoin(*cmd_arg, "", 1);
		str += 1;
	}
	else if (*str == '?')
	{
		value = ft_itoa(g_exit_status);
		*cmd_arg = ft_strjoin_free(*cmd_arg, value);
		free(value);
		str++;
	}
	else
	{
		key = find_key(str);
		if (lst_get_value(env, key))
			*cmd_arg = ft_strjoin_free(*cmd_arg, lst_get_value(env, key));
		free(key);
		while (ft_isalnum(*str) || *str == '_')
			str++;
	}
	return (str);
}

char	*parse_env(char *str, char **cmd_arg, t_list *env)
{
	if (*str == '$')
	{
		if (ft_strchr("\\;| ", *(str + 1)) || *(str + 1) == '\0')
		{
			*cmd_arg = ft_strnjoin(*cmd_arg, str, 1);
			str++;
		}
		else
		{
			if (*(str + 1) == '\"')
			{
				*cmd_arg = ft_strnjoin(*cmd_arg, str, 1);
				str++;
			}
			else
				str = env_put(str + 1, cmd_arg, env);
		}
	}
	return (str);
}
