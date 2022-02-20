/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_prompt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 17:46:43 by mmateo-t          #+#    #+#             */
/*   Updated: 2022/02/19 18:23:21 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*build_prompt(void)
{
	char	*prompt;
	char	*dir;
	char	*user;

	user = getvar("USER");
	dir = getvar("PWD");
	if (!dir)
		throw_error("Error building prompt");
	prompt = (char *)calloc(sizeof(char), MAXCOM);
	ft_strlcat(prompt, COLOR(1, 33), ft_strlen(COLOR(1, 33)) + 1);
	ft_strlcat(prompt, user, ft_strlen(prompt) + ft_strlen(user) + 1);
	ft_strlcat(prompt, NC, ft_strlen(prompt) + ft_strlen(NC) + 1);
	ft_strlcat(prompt, SIMBOL1, ft_strlen(prompt) + ft_strlen(SIMBOL1) + 1);
	ft_strlcat(prompt, COLOR(1, 34), ft_strlen(prompt)
		+ ft_strlen(COLOR(1, 34)) + 1);
	ft_strlcat(prompt, dir, ft_strlen(prompt) + ft_strlen(dir) + 1);
	ft_strlcat(prompt, NC, ft_strlen(prompt) + ft_strlen(NC) + 1);
	ft_strlcat(prompt, SIMBOL2, ft_strlen(prompt) + ft_strlen(SIMBOL2) + 1);
	free(dir);
	free(user);
	return (prompt);
}
