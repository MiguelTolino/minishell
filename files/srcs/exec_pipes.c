/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 19:57:35 by mmateo-t          #+#    #+#             */
/*   Updated: 2021/12/10 21:05:54 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/* void	exec_pipes(char ***cmd, int n_pipes)
{
	
	int *p[2];
	int *pid;

	pid = malloc(sizeof(int) * (n_pipes + 1));
	if(pipe(p) < 0)
		throw_error("Pipe Error");
	pid1 = fork();
	if (!pid1)
	{
		//dup2()
	}
	else if(pid1)
	{
		

	}
	else
		throw_error("Error in fork");
	
} */