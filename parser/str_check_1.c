#include "../include/minishell.h"

char	*pipe_check(char *str)
{
	if (*str == '|')
	{
		str++;
		while (*str == ' ')
			str++;
		if (*str == '|' || *str == ';' || *str == '\0')
		{
			if (*str == '|')
				g_exit_status = print_error(
						"syntax error near unexpected token", "`|\'", 258);
			else if (*str == ';')
				g_exit_status = print_error(
						"syntax error near unexpected token", "`;\'", 258);
			else if (*str == '\0')
				g_exit_status = print_error("syntax error",
						"multiline is not processed", 2);
			return (NULL);
		}
	}
	return (str);
}

char	*end_check(char *str)
{
	if (*str == ';')
	{
		str++;
		while (*str == ' ')
			str++;
		if (*str == ';' || *str == '|')
		{
			if (*str == ';')
				g_exit_status = print_error(
						"syntax error near unexpected token", "`;\'", 258);
			else
				g_exit_status = print_error(
						"syntax error near unexpected token", "`|\'", 258);
			return (NULL);
		}
	}
	return (str);
}

int	main_check(char *str)
{
	while (*str)
	{
		if (!ft_strchr("\\\"\'><|;", *str))
			str++;
		str = check_shielding(str);
		str = ft_check_quotes(str, '\"');
		if (str == NULL)
			return (1);
		str = ft_check_quotes(str, '\'');
		if (str == NULL)
			return (1);
		str = check_fd(str);
		if (!str)
			return (1);
		str = pipe_check(str);
		if (!str)
			return (1);
		str = end_check(str);
		if (!str)
			return (1);
		while (*str == ' ')
			str++;
	}
	return (0);
}

int	str_check(char *str)
{
	if (*str == ';' || *str == '|')
	{
		if (*str == ';')
			g_exit_status = print_error(
					"syntax error near unexpected token", "`;\'", 258);
		if (*str == '|')
			g_exit_status = print_error(
					"syntax error near unexpected token", "`|\'", 258);
		return (1);
	}
	return (main_check(str));
}
