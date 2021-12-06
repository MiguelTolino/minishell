/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_prompt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 17:46:43 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/12/06 11:54:01 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// COLOR + USER + @ + HOSTNAME + < + DIR + > $ 

char *set_directory(char *dir)
{
	int size = 1024;
	char *ptr;
	
	if ((dir = (char *)malloc((size_t)size)) != NULL)
    	ptr = getcwd(dir, (size_t)size);
	return(ptr);
}

void join_elements(char *prompt)
{
	ft_strlcat(prompt, COLOR(1, 34), ft_strlen(COLOR(1, 34)) + 1);
	ft_strlcat(prompt, vars.user, ft_strlen(prompt) + ft_strlen(vars.user) + 1);
	ft_strlcat(prompt, NC, ft_strlen(prompt) + ft_strlen(NC) + 1);
	ft_strlcat(prompt, "@", ft_strlen(prompt) + 2);
	ft_strlcat(prompt, COLOR(1, 33), ft_strlen(prompt) + ft_strlen(COLOR(1, 33)) + 1);
	ft_strlcat(prompt, vars.hostname, ft_strlen(prompt) + ft_strlen(vars.hostname) + 1);
	ft_strlcat(prompt, " < ", ft_strlen(prompt) + 3);
	ft_strlcat(prompt, COLOR(1, 31), ft_strlen(prompt) + ft_strlen(COLOR(1, 31)) + 1);
	ft_strlcat(prompt, vars.pwd, ft_strlen(prompt) + ft_strlen(vars.pwd) + 1);
	ft_strlcat(prompt, NC, ft_strlen(prompt) + ft_strlen(NC) + 1);
	ft_strlcat(prompt, SIMBOL, ft_strlen(prompt) + ft_strlen(SIMBOL) + 1);
}

char	*build_prompt(char *prompt_old) //FIXME: When 2 iterations prompt fails
{
	char *prompt;
	char *dir;

	prompt= (char *)malloc(sizeof(char) * 256);
	vars.pwd = set_directory(dir);
	join_elements(prompt);
	return (prompt);
}
