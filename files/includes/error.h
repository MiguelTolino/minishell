/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgirondo <rgirondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 21:27:24 by mmateo-t          #+#    #+#             */
/*   Updated: 2022/02/25 00:19:57 by rgirondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H
# define PROMPT_ERROR "Prompt Error\n"
# define PARSING_ERROR "Unexpected parse error near redirections"
# define PARSING_ERROR_OP_ARG "Unexpected parse error near operator arg"
# define PARSING_ERROR_OP "Unexpected parse error near operator"
# define PARSING_ERROR_PIPE "Unexpected parse error near pipe"
# define EXPORT_IDENT "Export not a valid identifier"
# define EXEC_ERROR 127

int	error_parsing(char *cmdline);
int	throw_set_error(const char *error, int error_code);

#endif