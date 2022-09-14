#include "../include/minishell.h"

void	free_all(char **arr)
{
	int	i;

	i = 0;
	if (arr)
	{
		while (arr[i])
		{
			free(arr[i]);
			i++;
		}
		free(arr);
	}
}

int	print_error(char *arg, char *msg, int ret)
{
	int	fd_out;

	fd_out = dup(STDOUT_FILENO);
	dup2(2, 1);
	printf("minishell: %s: %s\n", arg, msg);
	dup2(fd_out, 1);
	return (ret);
}

void	ft_sort(char **arr)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (arr[i])
	{
		j = 0;
		while (arr[j])
		{
			if (arr[j + 1] != NULL
				&& ft_strncmp(arr[j], arr[j + 1], ft_strlen(arr[j])) > 0)
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

char	*ft_strnjoin(char *s1, char *s2, int count)
{
	char	*tmp;
	char	*new_str;

	tmp = ft_substr(s2, 0, count);
	new_str = ft_strjoin_free(s1, tmp);
	free(tmp);
	return (new_str);
}
