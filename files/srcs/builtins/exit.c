/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 13:38:48 by mmateo-t          #+#    #+#             */
/*   Updated: 2022/02/15 13:50:25 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	exit(char **cmd)
{	
	if(!cmd[1])
		exit(EXIT_SUCCESS);
	if (global.exit_status = ft_atoi(cmd[1]))
		exit(global.exit_status);
}