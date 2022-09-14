#include "../include/minishell.h"

int	check_value(char *str)
{
	int	i;

	i = 0;
	if (str != NULL)
	{
		while (str[i] != '\0' && str[i] != '=')
			i++;
		if (str[i] == '=')
			return (0);
	}
	return (1);
}

char	**lst_to_env(t_list *lst)
{
	char	**env;
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = lst;
	env = malloc((ft_lstsize(tmp) + 1) * sizeof(char *));
	if (env == NULL)
		return (NULL);
	while (tmp)
	{
		if (!check_value(tmp->content))
		{
			env[i] = ft_strdup(tmp->content);
			i++;
		}
		tmp = tmp->next;
	}
	env[i] = NULL;
	return (env);
}

int	builtin_env(t_list **lst)
{
	t_list	*env;
	int		i;

	i = 0;
	env = *lst;
	if (env == NULL)
	{
		printf("%s\n", strerror(errno));
		return (2);
	}
	while (env)
	{
		if (!check_value(env->content))
		{
			ft_putstr_fd(env->content, 1);
			ft_putchar_fd('\n', 1);
		}
		env = env->next;
	}
	return (0);
}
