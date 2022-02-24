/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 09:55:58 by mmateo-t          #+#    #+#             */
/*   Updated: 2022/02/24 17:45:26 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	loop(t_shell *shell)
{
	char *trim;
	while (1)
	{
		shell->prompt = build_prompt();
		shell->cmdline = readline(shell->prompt);
		free(shell->prompt);
		if (shell->cmdline == NULL)
			exit_ctrld(shell->cmdline);
		trim = ft_strtrim(shell->cmdline, WHITESPACE);
		free(shell->cmdline);
		shell->cmdline = trim;
		if (!ft_strlen(shell->cmdline))
		{
			free(shell->cmdline);
			continue ;
		}
		add_history(shell->cmdline);
		if (quoting(shell))
		{
			free_shell(shell);
			continue ;
		}
		//test(*shell);
		if (parsing_errors(shell->cmdlist))
		{
			token_expansion(shell);
			parsing(shell);
			redirections(shell);
			if (!g_global.exec)
				execution(shell);
		}
		free_shell(shell); // If cmdline is empty ocurss a leak
		system("leaks minishell");
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_shell	shell;

	if (!envp)
	{
		printf("HOLA");
	}
	
	check_args(argc);
	init_shell(argv, envp);
	signal_handler();
	loop(&shell);
	dfree(g_global.env);
	dfree(g_global.env_export);
	return (g_global.exit_status);
}
