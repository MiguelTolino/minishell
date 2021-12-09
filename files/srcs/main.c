/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 09:55:58 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/12/07 19:29:48 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	char	*prompt;
	char	*cmdline;
	char	**cmds;
	int		pid;

	check_args(argc);
	while (1)
	{
		prompt = build_prompt(prompt);
		cmdline = readline(prompt);
		if (!ft_strlen(cmdline))
			continue;
		add_history(cmdline);
		cmds = parsing(cmdline);
		action(cmds, envp);
		free(cmdline);
	}
	return (0);
}
