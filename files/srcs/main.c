/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 09:55:58 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/12/10 19:22:22 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void init_shell()
{
printf("        .__       .__       .__           .__  .__   \n");
printf("  _____ |__| ____ |__| _____|  |__   ____ |  | |  |  \n");
printf(" /     \\|  |/    \\|  |/  ___/  |  \\_/ __ \\|  | |  |  \n");
printf("|  Y Y  \\  |   |  \\  |\\___ \\|   Y  \\  ___/|  |_|  |__\n");
printf("|__|_|  /__|___|  /__/____  >___|  /\\___  >____/____/\n");
printf("      \\/        \\/        \\/     \\/     \\/           \n\n");
}

int	main(int argc, char **argv, char **envp)
{
	char	*prompt;
	char	*cmdline;
	char	**cmds;
	int		is_exec;

	check_args(argc);
	init_shell();
	while (1)
	{
		prompt = build_prompt();
		cmdline = readline(prompt);
		if (!ft_strlen(cmdline))
			continue;
		add_history(cmdline);
		cmds = parsing(cmdline, envp);
		is_exec = action(cmds, envp);
		if(!is_exec)
			exec(cmds, envp);
		free(cmdline);
	}
	return (0);
}
