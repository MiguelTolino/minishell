/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dividing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 12:14:24 by mmateo-t          #+#    #+#             */
/*   Updated: 2022/01/26 20:11:22 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

//Divide by tokens and assign a type
/*
	1º Recorrer la lista hasta encontrar un espacio
	2º Crear una nueva lista de token y guardar el substring en dicha lista
	3º Asignar que tipo de palabra o comando es
	4º Terminar la lista de token y empezar con el siguiente comando
*/

unsigned int select_type(t_token *token, int old_type)
{
	size_t len;
	unsigned int type;

	type = 0;
	len = ft_strlen(token->word);

	if (!ft_strncmp(token->word, "<", len))
		return (FILE_IN);
	if (!ft_strncmp(token->word, "<<", len))
		return (HERE_DOC);
	if (!ft_strncmp(token->word, ">", len))
		return (FILE_OUT);
	if (!ft_strncmp(token->word, ">>", len))
		return (FILE_OUT_SUR);
	if (old_type == FILE_IN)
		return (OPEN_FILE);
	if (old_type == FILE_OUT)
		return (EXIT_FILE);
	if (old_type == HERE_DOC)
		return (LIMITOR);
	if (old_type == FILE_OUT_SUR)
		return (EXIT_FILE_RET);
	if (old_type < 0)
		return (CMD);
	if (old_type <= 1)
		return (ARG);
	return (type);
}

void ignore_spaces(char *cmd, int *i)
{
	while (cmd[*i] == ' ')
		(*i)++;
}

void save_token(char *cmd, t_list **token_list, int single, int doble)
{
	t_list *list;
	int i;
	int start;
	int old_type;
	t_token *token;

	i = 0;
	list = NULL;
	start = 0;
	old_type = -1;
	while (cmd[i])
	{
		ignore_spaces(cmd, &i);
		if (!cmd[i])
			break;
		start = i;
		while (cmd[i] != ' ')
		{
			ignore_quotes(cmd, '\'', &i, single);
			ignore_quotes(cmd, '\"', &i, doble);
			if (!cmd[i])
				break;
			i++;
		}
		token = (t_token *)malloc(sizeof(t_token));
		token->word = ft_substr(cmd, start, i - start);
		token->type = select_type(token, old_type);
		old_type = token->type;
		list = ft_lstnew(token);
		ft_lstadd_back(token_list, list);
	}
}

void dividing(t_shell *shell, int single, int doble)
{
	t_list *cmdlist;
	t_cmd_data *data;

	cmdlist = shell->cmdlist;
	while (cmdlist)
	{
		data = ((t_cmd_data *)cmdlist->content);
		save_token(data->cmd, &data->token, single, doble);
		cmdlist = cmdlist->next;
	}
}
