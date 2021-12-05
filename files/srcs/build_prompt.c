/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_prompt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 17:46:43 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/12/05 18:57:23 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char *set_directory(char *dir)
{
	int size = 1024;
	char *ptr;
	
	free(dir);
	if ((dir = (char *)malloc((size_t)size)) != NULL)
    	ptr = getcwd(dir, (size_t)size);
	return(ptr);
}

void join_elements(t_prompt prompt)
{
	ft_strlcat(prompt.simbol, COLOR(1, 34), ft_strlen(COLOR(1, 34)) + 1);
	ft_strlcat(prompt.simbol, prompt.user, ft_strlen(prompt.simbol) + ft_strlen(prompt.user) + 1);
	ft_strlcat(prompt.simbol, NC, ft_strlen(prompt.simbol) + ft_strlen(NC) + 1);
	ft_strlcat(prompt.simbol, "@", ft_strlen(prompt.simbol) + 2);
	ft_strlcat(prompt.simbol, COLOR(1, 33), ft_strlen(prompt.simbol) + ft_strlen(COLOR(1, 33)) + 1);
	ft_strlcat(prompt.simbol, prompt.hostname, ft_strlen(prompt.simbol) + ft_strlen(prompt.hostname) + 1);
	ft_strlcat(prompt.simbol, " < ", ft_strlen(prompt.simbol) + 3);
	ft_strlcat(prompt.simbol, COLOR(1, 31), ft_strlen(prompt.simbol) + ft_strlen(COLOR(1, 31)) + 1);
	ft_strlcat(prompt.simbol, prompt.dir, ft_strlen(prompt.simbol) + ft_strlen(prompt.dir) + 1);
	ft_strlcat(prompt.simbol, NC, ft_strlen(prompt.simbol) + ft_strlen(NC) + 1);
	ft_strlcat(prompt.simbol, SIMBOL, ft_strlen(prompt.simbol) + ft_strlen(SIMBOL) + 1);
}

char *save_var(char *str)
{
	char *var;

	var = ft_strchr(str, '=');
	var++;
	return (ft_strdup(var));
}

t_prompt	build_prompt(char **envp)
{
	int i;
	char *aux;
	t_prompt prompt;
	
	i = 0;
	prompt.simbol = (char *)malloc(sizeof(char) * 100);
	prompt.dir = set_directory(prompt.dir);
	while (envp[i])
	{
		if (aux = ft_strnstr(envp[i], "USER", ft_strlen(envp[i])))
			prompt.user = save_var(aux);
		if (aux = ft_strnstr(envp[i], "NAME", ft_strlen(envp[i])))
			prompt.hostname = save_var(aux);
		i++;
	}
	join_elements(prompt);
	return (prompt);
}
