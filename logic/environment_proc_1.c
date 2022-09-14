#include "../include/minishell.h"

t_list	*env_to_list(char **env)
{
	t_list	*lst_env;
	int		i;
	char	*str;

	i = 0;
	lst_env = NULL;
	while (env[i])
	{
		str = ft_strdup((env[i]));
		if (str == NULL)
			return (NULL);
		ft_lstadd_back(&lst_env, ft_lstnew(str));
		i++;
	}
	return (lst_env);
}

int	remove_first_list(t_list **list, char *key)
{
	t_list	*tmp;
	size_t	key_len;

	tmp = *list;
	key_len = ft_strlen(key);
	if (tmp != NULL && !ft_strncmp(tmp->content, key, key_len)
		&& (tmp->content[key_len] == '=' || tmp->content[key_len] == '\0'))
	{
		*list = tmp->next;
		free(tmp->content);
		free(tmp);
		return (0);
	}
	return (1);
}

void	remove_key(t_list **env, char *key)
{
	size_t	key_len;
	t_list	*p;
	t_list	*tmp;

	p = *env;
	tmp = p;
	key_len = ft_strlen(key);
	if (remove_first_list(env, key) == 0)
		return ;
	while (p != NULL)
	{
		if (!ft_strncmp(p->content, key, key_len)
			&& (p->content[key_len] == '=' || p->content[key_len] == '\0'))
			break ;
		tmp = p;
		p = p->next;
	}
	if (p != NULL)
	{
		tmp->next = p->next;
		free(p->content);
		free(p);
	}
}

int	append_list_elem(t_list **list, char *key, char *value)
{
	char	*content;
	char	*tmp;

	content = ft_strdup(key);
	if (content == NULL)
		return (1);
	if (value != NULL)
	{
		tmp = content;
		content = ft_strjoin(content, "=");
		free(tmp);
		tmp = content;
		content = ft_strjoin(content, value);
		if (tmp)
			free(tmp);
	}
	if (content == NULL)
		return (1);
	ft_lstadd_back(list, ft_lstnew(content));
	return (0);
}

char	*new_key_value(char *key, char *value)
{
	char	*str;
	char	*tmp;

	if (value)
	{
		str = ft_strjoin(key, "=");
		tmp = str;
		str = ft_strjoin(str, value);
		if (tmp)
			free(tmp);
	}
	else
		str = ft_strdup(key);
	return (str);
}
