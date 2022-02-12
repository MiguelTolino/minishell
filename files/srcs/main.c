/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgirondo <rgirondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 09:55:58 by mmateo-t          #+#    #+#             */
/*   Updated: 2022/02/12 18:31:33 by rgirondo         ###   ########.fr       */
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
		if (!ft_strlen(shell.cmdline))
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
		//parsing(&shell);
		token_expansion(&shell);
		test(shell);
		//redirections(&shell);
		//execution(&shell);
		//restore_fd();
		free_shell(&shell); // If cmdline is empty ocurss a leak
		//system("leaks minishell");
	}
	return (0);
}
