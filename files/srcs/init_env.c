/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 02:48:24 by mmateo-t          #+#    #+#             */
/*   Updated: 2022/02/25 02:58:28 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#define DECLARE "declare -x "

char	choose_letter(char letter)
{
	char	l;

	l = letter;
	if (letter == '[')
		l = 'a';
	if (letter == '{')
		l = '_';
	return (l);
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

char	**create_env_export(void)
{
	int		i;
	int		j;
	char	letter;
	char	**array;

	i = 0;
	j = 0;
	letter = 'A';
	array = (char **)ft_calloc(g_global.env_len + 1, sizeof(char *));
	while (i < g_global.env_len)
	{
		j = 0;
		while (g_global.env[j])
		{
			if (g_global.env[j][0] == letter)
				array[i++] = ft_strjoin(DECLARE, g_global.env[j]);
			j++;
		}
		letter++;
		letter = choose_letter(letter);
		if (letter == 96)
			break ;
	}
	return (array);
}
