/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 12:11:17 by mmateo-t          #+#    #+#             */
/*   Updated: 2022/01/25 20:25:20 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/* void del(void *content)
{
	t_list *token;

	token = ((t_cmd_data *)content)->token;
	ft_lstclear(&token, &free);
} */

void del(void *content)
{
	t_cmd_data *data;

	data = ((t_cmd_data *)content);
	free(data->cmd);
	free(content);
}

void free_shell(t_shell *shell)
{
	free(shell->cmdline);
	free(shell->prompt);
	ft_lstclear(&shell->cmdlist, del);
/* 	dup2(STDOUT_FILENO ,STDOUT_FILENO);
	dup2(STDIN_FILENO, STDIN_FILENO); */
}