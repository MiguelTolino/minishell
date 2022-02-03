/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 12:00:24 by mmateo-t          #+#    #+#             */
/*   Updated: 2022/02/03 12:19:45 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// TODO:
// 1.Recorrer la lista hasta encontrar tipos de redirecciones
// 2.Si existen abrir cada fd correspondiente y cambiar con dup2
// 3.Recuerda cerrar los fd al final

void select_redirection(t_token *token)
{
	int fd;

	fd = 0;
	if (token->type == OPEN_FILE)
	{
		fd = open(token->word, O_RDONLY);
		if (fd < 0)
			throw_error("Error opening a file");
		if (dup2(fd, STDIN_FILENO) < 0)
			throw_error("Error in redirection");
	}
	if (token->type == EXIT_FILE)
	{
		fd = open(token->word, O_CREAT | O_WRONLY, 0644);
		if (fd < 0)
			throw_error("Error opening a file");
		if (dup2(fd, STDOUT_FILENO) < 0)
			throw_error("Error in redirection");
	}
	if (token->type == EXIT_FILE_RET)
	{
		fd = open(token->word, O_CREAT | O_WRONLY | O_APPEND, 0644);
		if (fd < 0)
			throw_error("Error opening a file");
		if (dup2(fd, STDOUT_FILENO) < 0)
			throw_error("Error in redirection");
	}
	if (token->type == LIMITOR)
	{
		fd = open(token->word, O_RDONLY);
		// TODO: HERE_DOC
	}
	if (fd)
		close(fd);
}

void redirections(t_shell *shell)
{
	t_list *list;
	t_list *token_list;
	t_cmd_data *cmd_data;
	t_token *token;

	list = shell->cmdlist;
	token_list = NULL;
	while (list)
	{
		cmd_data = ((t_cmd_data *)list->content);
		token_list = ((t_list *)cmd_data->token);
		while (token_list)
		{
			token = ((t_token *)token_list->content);
			select_redirection(token);
			token_list = token_list->next;
		}
		list = list->next;
	}
}