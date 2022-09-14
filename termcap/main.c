/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsusanna <gsusanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 19:14:27 by gsusanna          #+#    #+#             */
/*   Updated: 2021/05/07 17:15:09 by gsusanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_main_struct_init(t_input *input)
{
	input->len = 0;
	input->rest = ft_strdup("");
	input->save_line = NULL;
	if (input->rest == NULL)
	{
		free(input->rest);
		return (0);
	}
	input->history = ft_create_history();
	if (input->history == NULL)
	{
		free(input->rest);
		return (0);
	}
	history_from_file(input);
	return (0);
}

void	shlvl_up(t_list **env)
{
	int		lvl;
	char	*value;

	value = lst_get_value(*env, "SHLVL");
	if (value == NULL)
	{
		append_list_elem(env, "SHLVL", "1");
		return ;
	}
	lvl = ft_atoi(value);
	lvl++;
	value = ft_itoa(lvl);
	change_or_append_str(env, "SHLVL", value);
	free(value);
}

int	main(int argc, char **argv, char **envp)
{
	char	*term_name;
	t_input	input;
	t_list	*env;

	env = env_to_list(envp);
	shlvl_up(&env);
	(void) argv;
	(void) argc;
	g_exit_status = 0;
	signal(SIGINT, manage_signals);
	signal(SIGQUIT, manage_signals);
	term_name = "xterm-256color";
	if (!isatty(STDIN_FILENO))
		return (1);
	if (tgetent(NULL, term_name) < 1)
		ft_err("Environment error!");
	ft_main_struct_init(&input);
	while (42)
	{
		term_init(1);
		write(1, TAG, TAG_LEN);
		tputs(save_cursor, 1, ft_putchar);
		get_next_input_line(&input, &env);
	}
	return (g_exit_status);
}
