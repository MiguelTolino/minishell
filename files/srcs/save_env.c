/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 20:29:22 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/12/05 20:44:45 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char *save_var(char *str)
{
	char *var;

	var = ft_strchr(str, '=');
	var++;
	return (ft_strdup(var));
}

int	save_env(char **envp)
{
	int i;
	char *aux;

	i = 0;
	while (envp[i])
	{
		if (aux = ft_strnstr(envp[i], "USER", ft_strlen(envp[i])))
			vars.user = save_var(aux);
		if (aux = ft_strnstr(envp[i], "NAME", ft_strlen(envp[i])))
			vars.hostname = save_var(aux);
		if (aux = ft_strnstr(envp[i], "HOME", ft_strlen(envp[i])))
			vars.home = save_var(aux);
		if (aux = ft_strnstr(envp[i], "PWD", ft_strlen(envp[i])))
			vars.pwd = save_var(aux);
		i++;
	}
	return (0);
}