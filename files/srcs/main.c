/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 09:55:58 by mmateo-t          #+#    #+#             */
/*   Updated: 2022/02/19 23:05:32 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	init_shell(void)
{
	printf("%s        .__       .__       .__           .__  .__   \n",
		COLOR(1, 31));
	printf("  _____ |__| ____ |__| _____|  |__   ____ |  | |  |  \n");
	printf(" /     \\|  |/    \\|  |/  ___/  |  \\_/ __ \\|  | |  |  \n");
	printf("|  Y Y  \\  |   |  \\  |\\___ \\|   Y  \\  ___/|  |_|  |__\n");
	printf("|__|_|  /__|___|  /__/____  >___|  /\\___  >____/____/\n");
	printf("      \\/        \\/        \\/     \\/     \\/           \n\n%s",
		NC);
}

int	main(int argc, char **argv, char **envp)
{
	t_shell	shell;

	check_args(argc);
	init_shell();
	init_global(envp, argv);
	signal_handler();
	while (1)
	{
		shell.prompt = build_prompt();
		shell.cmdline = readline(shell.prompt);
		if (shell.cmdline == NULL)
			exit_ctrld(shell);
		if (!ft_strlen(shell.cmdline) || error_parsing(shell.cmdline))
		{
			free(shell.prompt);
			free(shell.cmdline);
			continue ;
		}
		add_history(shell.cmdline);
		if (quoting(&shell))
		{
			free_shell(&shell);
			continue ;
		}
		token_expansion(&shell);
		parsing(&shell);
		redirections(&shell);
		execution(&shell);
		//test(shell);
		free_shell(&shell); // If cmdline is empty ocurss a leak
		//system("leaks minishell");
	}
	return (0);
}
