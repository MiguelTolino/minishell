/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 21:27:24 by mmateo-t          #+#    #+#             */
/*   Updated: 2022/02/21 23:41:34 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H
# define PROMPT_ERROR "Prompt Error\n"
# define EXEC_ERROR 127


int	error_parsing(char *cmdline);

#endif