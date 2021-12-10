/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:50:51 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/12/10 19:20:45 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	check_access(char *cmd, char *path)
{
	char *aux;
	char *full_cmd;
	int bool;

	bool = 0;
	aux = ft_strjoin(path, "/");
	full_cmd = ft_strjoin(aux, cmd);
	if (!(access(full_cmd, X_OK)))
		bool = 1;
	return (bool);
}

char *add_path(char *cmd, char **envp)
{
	char *full_cmd;
	char *path;
	char **paths;
	int i;
	int bool;
	char *aux;

	i = 0;
	path = getenv("PATH");
	paths = ft_split(path, ':');
	while (paths[i])
	{
		bool = check_access(cmd, paths[i]);
		if (bool)
		{
			aux = ft_strjoin(paths[i], "/");
			full_cmd = ft_strjoin(aux, cmd);
			return(full_cmd);
		}
		i++;
	}
	return(NULL);
}