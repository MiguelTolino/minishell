/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 20:02:48 by mmateo-t          #+#    #+#             */
/*   Updated: 2022/01/17 18:58:57 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void test(t_shell shell)
{
	t_list *list;
	t_list *token_list;
	t_cmd_data *cmd_data;
	list = shell.cmdlist;
	token_list = NULL;
	while (list)
	{
		cmd_data = ((t_cmd_data *)list->content);
		printf("CMD:|%s|\n\n", cmd_data->cmd);
		token_list = ((t_list *)cmd_data->token);
		while (token_list)
		{
			printf("WORD:|%s|\n", ((t_token *)token_list->content)->word);
			printf("TYPE:|%i|\n", ((t_token *)token_list->content)->type);
			printf("\n");
			token_list = token_list->next;
		}
		list = list->next;
	}
}
