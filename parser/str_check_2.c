#include "../include/minishell.h"

char	*check_shielding(char *str)
{
	if (*str == '\\')
	{
		str++;
		if (*str != '\0')
			str++;
	}
	return (str);
}

char	*ft_check_quotes(char *str, char type)
{
	if (*str == type)
	{
		str++;
		while (*str != type && *str)
		{
			if (type == '\"' && *str == '\\')
				str++;
			if (*str != '\0')
				str++;
		}
		if (*str == '\0')
		{
			g_exit_status = print_error("syntax error",
					"multiline isn\'t processed", 2);
			return (NULL);
		}
		str++;
	}
	return (str);
}

int	fd_check_error(const char *str)
{
	char	*error;
	int		check;

	check = 0;
	error = ft_substr(str, 0, 1);
	if (*str == '\0')
	{
		check = 1;
		g_exit_status = print_error("syntax error near unexpected token",
				"`newline\'", 258);
	}
	else if (ft_strchr("><;|", *str))
	{
		check = 1;
		g_exit_status = print_error("syntax error near unexpected token",
				error, 258);
	}
	free(error);
	return (check);
}

static char	*check_syntax(char *str)
{
	if (!ft_strncmp(">>", str, 2))
		str += 2;
	else if (*str == '>')
		str++;
	else if (*str == '<')
		str++;
	while (*str == ' ')
		str++;
	if (fd_check_error(str))
		return (NULL);
	return (str);
}

char	*check_fd(char *str)
{
	if (*str == '>' || *str == '<')
	{
		str = check_syntax(str);
		if (!str)
			return (NULL);
		while (!ft_strchr("><|; ", *str) && *str)
		{
			str = check_shielding(str);
			str = ft_check_quotes(str, '\"');
			if (str == NULL)
				return (NULL);
			str = ft_check_quotes(str, '\'');
			if (str == NULL)
				return (NULL);
			while (!ft_strchr("\\\'\"><; ", *str))
				str++;
		}
	}
	return (str);
}
