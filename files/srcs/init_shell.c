/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 13:38:13 by mmateo-t          #+#    #+#             */
/*   Updated: 2022/02/24 11:52:15 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#define DECLARE "declare -x "

char **create_env_export(void)
{
	int i;
	int j;
	char letter;
	char **array;

	i = 0;
	j = 0;
	letter = 'A';
	array = (char **)malloc(sizeof(char *) * g_global.env_len + 1);
	array[g_global.env_len] = NULL;
	while (i < g_global.env_len)
	{
		j = 0;
		while (g_global.env[j])
		{
			if (g_global.env[j][0] == letter)
				array[i++] = ft_strjoin(DECLARE, g_global.env[j]); 
			j++;
		}
		if (letter == '_')
			break;
		letter++;
		if (letter == '{')
			letter = '_';
	}
	return (array);
}

void	check_shlvl(void)
{
	char *var;
	int	lvl;
	char *new;

	var = getvar("SHLVL");
	if (!var)
		add_new("SHLVL=1");
	else
	{
		lvl = ft_atoi(var);
		lvl++;
		free(var);
		var = ft_itoa(lvl);
		new = ft_strjoin("SHLVL=", var);
		change_val("SHLVL", new);
		free(new);
	}
	free(var);
}

void	print_msg(void)
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

char	**init_env(char **envp)
{
	char	**new_envp;
	int		i;

	new_envp = (char **)malloc(sizeof(char *) * g_global.env_len);
	i = 0;
	while (envp[i])
	{
		new_envp[i] = ft_strdup(envp[i]);
		i++;
	}
	new_envp[i] = NULL;
	return (new_envp);
}

void	init_g_global(char **envp, char **argv)
{
	int	i;

	i = 0;
	while (envp[i])
		i++;
	g_global.env_len = (i + 2);
	g_global.env = init_env(envp);
	g_global.env_export = create_env_export();
	g_global.exit_status = 0;
	g_global.fd_stdin = dup(STDIN_FILENO);
	g_global.fd_stdout = dup(STDOUT_FILENO);
	g_global.exec = false;
	g_global.signal_status = 0;
	g_global.whereami = 0;
	(void)argv;
}

int	init_shell(char **argv, char **envp)
{
	print_msg();
	init_g_global(envp, argv);
	check_shlvl();
	return (0);
}
