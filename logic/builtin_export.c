#include "../include/minishell.h"

char	**lst_to_export(t_list *lst)
{
	char	**exp;
	int		i;

	i = 0;
	exp = ft_calloc(ft_lstsize(lst) + 1, sizeof(char *));
	while (lst)
	{
		if (lst->content[0] == '_' && lst->content[1] == '=')
		{
			lst = lst->next;
			continue ;
		}
		exp[i] = ft_strdup(lst->content);
		if (exp[i] == NULL)
		{
			free_all(exp);
			return (NULL);
		}
		i++;
		lst = lst->next;
	}
	exp[i] = NULL;
	return (exp);
}

int	put_export(t_list *lst)
{
	int		i;
	int		j;
	char	**exp;

	i = 0;
	exp = lst_to_export(lst);
	ft_sort(exp);
	while (exp[i])
	{
		j = 0;
		ft_putstr_fd("declare -x ", 1);
		while (exp[i][j] != '\0' && exp[i][j] != '=')
			ft_putchar_fd(exp[i][j++], 1);
		if (exp[i][j++] == '=')
		{
			ft_putchar_fd('=', 1);
			ft_putchar_fd('"', 1);
			ft_putstr_fd(&exp[i][j], 1);
			ft_putchar_fd('"', 1);
		}
		ft_putstr_fd("\n", 1);
		i++;
	}
	free_all(exp);
	return (0);
}

int	split_proc_str(t_list **lst, char *str)
{
	int		key_len;
	char	*key;
	char	*value;

	key_len = 0;
	value = NULL;
	while (str[key_len] != '\0' && str[key_len] != '=')
		key_len++;
	key = ft_substr(str, 0, key_len);
	if (key == NULL)
		return (print_error("export", strerror(errno), 2));
	if (str[key_len] != '\0')
		value = &str[key_len + 1];
	if (change_or_append_str(lst, key, value))
	{
		free(key);
		return (print_error("export", strerror(errno), 2));
	}
	free(key);
	return (0);
}

static int	ft_check_arg(char *arg)
{
	int	i;

	i = 0;
	if (!(ft_isalpha(arg[0]) || arg[0] == '_'))
		return (1);
	while (arg[i] != '\0' && arg[i] != '=')
	{
		if (!ft_isalnum(arg[i]) && arg[i] != '_')
			return (1);
		i++;
	}
	return (0);
}

int	builtin_export(t_list **env, char **arg)
{
	int	i;
	int	check;

	i = 1;
	if (arg[1] == NULL)
		return (put_export(*env));
	else
	{
		while (arg[i])
		{
			if (ft_check_arg(arg[i]))
			{
				print_error(arg[i], "not a valid identifier", 1);
				i++;
				continue ;
			}
			check = split_proc_str(env, arg[i]);
			if (check)
				return (check);
			i++;
		}
	}
	return (0);
}
