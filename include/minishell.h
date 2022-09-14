/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsusanna <gsusanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 15:40:28 by gsusanna          #+#    #+#             */
/*   Updated: 2021/05/07 17:24:01 by gsusanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <termios.h>
# include <signal.h>
# include <term.h>
# include <string.h>
# include <curses.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include <sys/ioctl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <errno.h>
# include <dirent.h>

# define	PATH_MAX 1024
# define	PIPE '|'
# define	TAG_LEN 20
# define	TAG "\e[96mMinishell:\e[0m "

typedef struct s_dhistory
{
	t_dlist	*root;
	t_dlist	*pointer;
}			t_dhistory;

typedef struct s_input
{
	int			len;
	char		*rest;
	char		*save_line;
	int			h_flag;
	t_dhistory	*history;
}				t_input;

typedef struct s_cmd
{
	char			*cmd;
	char			**arg;
	int				fd_in;
	int				fd_out;
	int				type;
	struct s_cmd	*next;
}					t_cmd;

int	g_exit_status;

int				ft_main_struct_init(t_input *input);
void			ft_main_struct_prep(t_input *input);

/************************************************/
/**				history fuctions	           **/
/************************************************/

t_dhistory		*ft_create_history(void);
void			history_from_file(t_input *input);
void			history_to_file(t_input *input);
void			ft_lst_add_history(t_dhistory *history, char *str);
char			*ft_history_up(t_dhistory *history);
char			*ft_history_down(t_dhistory *history);

/************************************************/
/**			keys functions                     **/
/************************************************/

int				get_next_input_line(t_input *input, t_list **env);

int				ft_pressed_key(char *str, t_input *input);
void			ft_pressed_enter(t_input *input, int read_result, char *buf);

void			ft_key_backspace(t_input *input);
void			ft_key_up(t_input *input);
void			ft_key_down(t_input *input);
void			ft_ctrl_d(t_input *input);
int				ft_ctrl_c(t_input *input);
void			input_put_str(t_input *input, char *str);

/************************************************/
/**				termcap functions			   **/
/************************************************/

void			term_init(int i);
int				is_empty_string(char *line);
void			manage_signals(int code);

/**********************************************/
/************* environment_proc.c *************/
/**********************************************/
t_list			*env_to_list(char **env);
int				remove_first_list(t_list **list, char *key);
void			remove_key(t_list **env, char *key);
int				append_list_elem(t_list **list, char *key, char *value);
char			*new_key_value(char *key, char *value);
int				change_or_append_str(t_list **lst, char *key, char *value);
int				change_value(t_list **list, char *key, char *value);
char			*lst_get_value(t_list *list, char *key);

/**********************************************/
/***************** builtin_cmds ***************/
/**********************************************/
void			free_all(char **arr);
int				print_error(char *arg, char *msg, int ret);
int				builtin_cd(char *arg, t_list **env);
int				builtin_echo(char **arg);
int				builtin_export(t_list **lst, char **arg);
int				builtin_pwd(void);
int				builtin_unset(t_list **lst, char **arg);
int				builtin_exit(char **arg);
int				status_proc(char *numbers);
char			**lst_to_env(t_list *lst);
int				builtin_env(t_list **lst);

/*
 * PIPES
 */
int				pipe_count(t_cmd *cmd);
int				close_all(int **fd, int p_count);
int				**pipe_all(int p_count);
void			dup_all(int i, int p_count, int **fd);
int				pipe_proc(t_list **env, t_cmd *cmd);
int				command_call(t_list **env, t_cmd *cmd);
char			*cmd_proccessing(char *cmd, t_list *env);

/*
 * PARSER
 */
void			ft_parse(char *str, t_list **env);
char			*ft_shielding(char *str, char **cmd_arg, int type);
char			*parse_env(char *str, char **cmd_arg, t_list *env);
char			*single_quotes(char *str, char **cmd_arg);
char			*double_quotes(char *str, char **cmd_arg, t_list *env);
char			*parse_fd(char *str, t_cmd *cmd, t_list *env);
int				str_check(char *str);
char			*add_chars(char *str, char **cmd_arg, char *stop_symbols);

/*
 * TOKEN CHECK
 */
char			*check_shielding(char *str);
char			*ft_check_quotes(char *str, char type);
int				fd_check_error(const char *str);
char			*check_fd(char *str);

/*
 * CMD INIT
 */
t_cmd			*cmd_init(int type);
void			cmd_add_back(t_cmd **cmd, t_cmd *new_cmd);
void			cmd_get_arg(t_list *lst, t_cmd *cmd);
void			cmd_free(t_cmd **cmd);

/*
 * UTILS
 */
void			ft_sort(char **arr);
char			*ft_strnjoin(char *s1, char *s2, int count);
void			free_lst(t_list *lst);

#endif
