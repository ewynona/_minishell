#include "../include/minishell.h"

int	change_or_append_str(t_list **lst, char *key, char *value)
{
	int	check;

	check = change_value(lst, key, value);
	if (check == 1)
	{
		if (append_list_elem(lst, key, value) == 1)
			return (print_error("", strerror(errno), 1));
	}
	else if (check == -1)
		return (print_error("", strerror(errno), 1));
	return (0);
}

int	change_value(t_list **list, char *key, char *value)
{
	size_t	key_len;
	t_list	*p;

	p = *list;
	key_len = ft_strlen(key);
	while (p)
	{
		if (!ft_strncmp(p->content, key, key_len)
			&& (p->content[key_len] == '=' || p->content[key_len] == '\0'))
			break ;
		p = p->next;
	}
	if (p == NULL)
		return (1);
	else
	{
		free(p->content);
		p->content = new_key_value(key, value);
		if (p->content == NULL)
			return (-1);
	}
	return (0);
}

/* return NULL if nothing was found */
char	*lst_get_value(t_list *list, char *key)
{
	char	*value;
	size_t	key_len;

	key_len = ft_strlen(key);
	value = NULL;
	while (list)
	{
		if (!ft_strncmp(list->content, key, key_len)
			&& list->content[key_len] == '=')
			break ;
		list = list->next;
	}
	if (list != NULL)
		if (list->content != NULL)
			value = &list->content[key_len + 1];
	return (value);
}
