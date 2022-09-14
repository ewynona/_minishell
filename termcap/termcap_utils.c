/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsusanna <gsusanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 03:46:39 by gsusanna          #+#    #+#             */
/*   Updated: 2021/05/07 17:24:18 by gsusanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	term_init(int i)
{
	struct termios	new_term;

	if (i == 1)
	{
		if (tcgetattr(0, &new_term))
			ft_err("tcgetattr");
		new_term.c_lflag &= ~(ECHO);
		new_term.c_lflag &= ~(ICANON);
		new_term.c_lflag &= ~(ISIG);
		tcsetattr(0, TCSANOW, &new_term);
		tputs(tgetstr("ks", NULL), 1, ft_putchar);
	}
	else if (i == 0)
	{
		if (tcgetattr(0, &new_term))
			ft_err("tcgetattr");
		new_term.c_lflag |= (ECHO);
		new_term.c_lflag |= (ICANON);
		new_term.c_lflag |= (ISIG);
		tcsetattr(0, TCSANOW, &new_term);
		tputs(tgetstr("ke", NULL), 1, ft_putchar);
		write(STDOUT_FILENO, "\n", 1);
	}
}
