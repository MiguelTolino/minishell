/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 09:55:58 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/12/11 11:56:39 by mmateo-t         ###   ########.fr       */
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
		if (ft_strlen(shell.cmdline))
			add_history(shell.cmdline);
/* 		n_pipes = search_pipes(cmdline);
		if (n_pipes)
		{
			cmds_pipe = parsing_pipes(cmdline, n_pipes);
			exec_pipes(cmds_pipe);
		}
		else
		{
		*/
 	/*	shell.cmds = parsing(shell.cmdline, envp);
		shell.is_exec = action(shell.cmds, envp);
		if(!shell.is_exec)
			exec(shell.cmds, envp);
		*/
		shell.cmd = check_cmd(shell.cmdline);
		if (!shell.cmd)
			perror("CMD does not have permissions");
		free(shell.cmdline);
		free(shell.prompt);
	}
	return (0);
}
