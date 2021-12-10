/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 09:55:58 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/12/10 21:47:08 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void init_shell()
{
printf("%s        .__       .__       .__           .__  .__   \n", COLOR(1, 31));
printf("  _____ |__| ____ |__| _____|  |__   ____ |  | |  |  \n");
printf(" /     \\|  |/    \\|  |/  ___/  |  \\_/ __ \\|  | |  |  \n");
printf("|  Y Y  \\  |   |  \\  |\\___ \\|   Y  \\  ___/|  |_|  |__\n");
printf("|__|_|  /__|___|  /__/____  >___|  /\\___  >____/____/\n");
printf("      \\/        \\/        \\/     \\/     \\/           \n\n%s", NC);
}

int	main(int argc, char **argv, char **envp)
{
	t_shell shell;

	check_args(argc);
	init_shell();
	while (1)
	{
		shell.prompt = build_prompt();
		shell.cmdline = readline(shell.prompt);
		if (!ft_strlen(shell.cmdline))
			continue;
		add_history(shell.cmdline);
/* 		n_pipes = search_pipes(cmdline);
		if (n_pipes)
		{
			cmds_pipe = parsing_pipes(cmdline, n_pipes);
			exec_pipes(cmds_pipe);
		}
		else
		{
 		cmds = parsing(cmdline, envp);
		is_exec = action(cmds, envp);
		if(!is_exec)
			exec(cmds, envp);
		} */
		free(shell.cmdline);
		free(shell.prompt);
	}
	return (0);
}
