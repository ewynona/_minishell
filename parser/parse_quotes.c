#include "../include/minishell.h"

char	*single_quotes(char *str, char **cmd_arg)
{
	int		size;
	char	*tmp;

	if (*str != '\'')
		return (str);
	size = 0;
	str++;
	while (str[size] && str[size] != '\'')
		size++;
	if (str[size] == '\0')
	{
		g_exit_status = print_error("syntax error",
				"multiline isn\'t processed", 2);
		return (NULL);
	}
	tmp = ft_calloc(size + 1, sizeof(char));
	size = 0;
	while (str[size] != '\'')
	{
		tmp[size] = str[size];
		size++;
	}
	*cmd_arg = ft_strjoin_free(*cmd_arg, tmp);
	free(tmp);
	return (&str[size + 1]);
}

char	*double_quotes(char *str, char **cmd_arg, t_list *env)
{
	int		i;
	char	*tmp;

	if (str[0] != '\"')
		return (str);
	str++;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\\')
			i++;
		if (str[i])
			i++;
	}
	tmp = ft_calloc(i + 1, sizeof(char));
	while (*str && *str != '\"')
	{
		str = ft_shielding(str, &tmp, '\"');
		str = parse_env(str, &tmp, env);
		str = add_chars(str, &tmp, "\\\"$");
	}
	*cmd_arg = ft_strjoin_free(*cmd_arg, tmp);
	free(tmp);
	return (str + 1);
}
