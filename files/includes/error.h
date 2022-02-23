/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 21:27:24 by mmateo-t          #+#    #+#             */
/*   Updated: 2022/02/23 19:10:08 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H
# define PROMPT_ERROR "Prompt Error\n"
# define PARSING_ERROR "Unexpected parse error near redirections"
# define EXEC_ERROR 127

int	error_parsing(char *cmdline);

#endif