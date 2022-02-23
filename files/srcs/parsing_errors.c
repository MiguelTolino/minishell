/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_errors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:32:26 by mmateo-t          #+#    #+#             */
/*   Updated: 2022/02/23 19:04:50 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* int		validate_token(t_list *cmdlist)
{
	t_cmd_data *data;
	t_list *token_list;
	t_token *token;
	t_token *next_token;

	while (cmdlist)
	{
		data = ((t_cmd_data *)cmdlist->content);
		token_list = data->token;
		while (token_list)
		{
			token = (t_token *)token_list->content;
			next_token = (t_token *)token_list->next->content;
			if ((token->type >= 2 && token->type <= 5) && ((next_token->type >= 2 && next_token->type <= 5 ) || !next_token
				|| (is_filename(next_token->word) && !next_token->quote)))
			{
				g_global.exit_status = EXIT_FAILURE;
				throw_error("Unexpected parse error near redirections");
				return (1);
			}
 			if (token_list->next == NULL)
				break;
			token_list = token_list->next;
		}
		cmdlist = cmdlist->next;
	}
	return (0);
}

void	parsing_errors(t_list *cmdlist)
{
	ft_lstiter()
} */