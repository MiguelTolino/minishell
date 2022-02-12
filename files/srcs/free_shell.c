/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 12:11:17 by mmateo-t          #+#    #+#             */
/*   Updated: 2022/02/08 22:20:33 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	restore_fd(void)
{
	dup2(global.fd_stdin, STDIN_FILENO);
	dup2(global.fd_stdout, STDOUT_FILENO);
}

 void del_token(void *content)
{
	t_token *token;

	token = ((t_token *)content);
	free(token->word);
	free(token);
}

void	del_data(void *content)
{
	t_cmd_data	*data;
	t_list		*token;

	data = ((t_cmd_data *)content);
	free(data->cmd);
	//dfree(data->exec_cmd);
	token = data->token;
	ft_lstclear(&token, del_token);
	free(data);
}

void	free_shell(t_shell *shell)
{
	free(shell->cmdline);
	free(shell->prompt);
	ft_lstclear(&shell->cmdlist, del_data);
	restore_fd();
}
 