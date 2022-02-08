/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 12:11:17 by mmateo-t          #+#    #+#             */
/*   Updated: 2022/02/03 20:38:41 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	restore_fd(void)
{
	dup2(STDIN_FILENO, STDIN_FILENO);
	dup2(STDOUT_FILENO, STDOUT_FILENO);
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
 