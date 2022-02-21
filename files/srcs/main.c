/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 09:55:58 by mmateo-t          #+#    #+#             */
/*   Updated: 2022/02/21 16:18:24 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"



int	main(int argc, char **argv, char **envp)
{
	t_shell	shell;

	check_args(argc);
	init_shell(argv, envp);
	signal_handler();
	while (1)
	{
		shell.prompt = build_prompt();
		shell.cmdline = readline(shell.prompt);
		if (shell.cmdline == NULL || !shell.prompt)
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
		token_expansion(&shell);
		parsing(&shell);
	//	test(shell);
		redirections(&shell);
		execution(&shell);
		free_shell(&shell); // If cmdline is empty ocurss a leak
		//system("leaks minishell");
	}
	dfree(global.env);
	return (0);
}
