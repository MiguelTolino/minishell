/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 09:55:58 by mmateo-t          #+#    #+#             */
/*   Updated: 2022/02/25 02:35:59 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*trim_cmdline(char *cmdline)
{
	char	*trim;

	trim = ft_strtrim(cmdline, WHITESPACE);
	free(cmdline);
	return (trim);
}

void	exp_pars_redir_exec(t_shell *shell)
{
	token_expansion(shell);
	parsing(shell);
	redirections(shell);
	if (!g_global.exec)
		execution(shell);
	free_shell(shell);
}

void	loop(t_shell *shell)
{
	while (1)
	{
		signal_handler();
		shell->prompt = build_prompt();
		shell->cmdline = readline(shell->prompt);
		free(shell->prompt);
		if (shell->cmdline == NULL)
			exit_ctrld(shell->cmdline);
		shell->cmdline = trim_cmdline(shell->cmdline);
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
		exp_pars_redir_exec(shell);
		system("leaks minishell");
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_shell	shell;

	check_args(argc);
	init_shell(argv, envp);
	signal_handler();
	loop(&shell);
	dfree(g_global.env);
	dfree(g_global.env_export);
	return (g_global.exit_status);
}
