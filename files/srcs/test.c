/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 20:02:48 by mmateo-t          #+#    #+#             */
/*   Updated: 2022/02/02 14:22:22 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void print(void *content)
{
	t_cmd_data *data;
	data = (t_cmd_data *)content;

	printf("ITER:%s\t", data->cmd);
	printf("\n");
}

void test(t_shell shell)
{
	t_list *token_list;
	t_cmd_data *cmd_data;
	token_list = NULL;
	printf("CMDLINE:|%s|\n\n", shell.cmdline);
	while (shell.cmdlist)
	{
		cmd_data = ((t_cmd_data *)shell.cmdlist->content);
		printf("CMD:|%s|\n", cmd_data->cmd);
/* 		token_list = ((t_list *)cmd_data->token);
		printf("TOKENS\n");
		printf("------\n");
		while (token_list)
		{
			printf("WORD:|%s|\n", ((t_token *)token_list->content)->word);
			printf("TYPE:|%i|\n", ((t_token *)token_list->content)->type);
			printf("\n");
			token_list = token_list->next;
		} */
/* 		printf("EXEC_CMD:");
		while(*cmd_data->exec_cmd)
		{
			printf("[%s]", *cmd_data->exec_cmd);
			cmd_data->exec_cmd++;
		}
		printf("\n"); */
		shell.cmdlist = shell.cmdlist->next;
	}
}
