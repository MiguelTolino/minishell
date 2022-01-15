/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dividing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 12:14:24 by mmateo-t          #+#    #+#             */
/*   Updated: 2022/01/15 19:49:08 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

//TODO: Divide by tokens and assign a type
/*
	1º Recorrer la lista hasta encontrar un spacio
	2º Crear una nueva lista de token y guardar el substring en dicha lista
	3º Asignar que tipo de palabra o comando es
	4º Terminar la lista de token y empezar con el siguiente comando
*/

void	ignore_spaces(char *cmd, int *i)
{

	while (cmd[*i] == ' ')
	{
			(*i)++;
	}
		//rintf("i:%i\n", *i);
}

void	save_token(char *cmd, t_list *token_list, int single, int doble)
{
	t_list *list;
	int i;
	int start;
	int len;
	t_token *token;

	i = 0;
	list = NULL;
	start = 0;
	while (cmd[i])
	{
		ignore_spaces(cmd, &i);
		if (!cmd[i])
			break;
		start = i;
		ignore_quotes(cmd, '\'', &i, single);
		ignore_quotes(cmd, '\"', &i, doble);
		while (cmd[i] != ' ')
		{
			if (!cmd[i])
				break;
			i++;
		}
		token = (t_token *)malloc(sizeof(t_token));
		printf("START:%i\n", start);
		printf("i:%i\n", i);
		token->word = ft_substr(cmd, start, i - start);
		list = ft_lstnew(token);
		ft_lstadd_back(&token_list, list);
		printf("TOKEN:%s\n", token->word);
	}
	printf ("-----------\n");
}

void dividing(t_shell *shell, int single, int doble)
{
	t_list *cmdlist;
	t_cmd_data * data;

	cmdlist = shell->cmdlist;
	while (cmdlist)
	{
		data = ((t_cmd_data*)cmdlist->content);
		printf("CMD:|%s|\n", data->cmd);
		save_token(data->cmd, data->token, single, doble);
		cmdlist = cmdlist->next;
	}
}