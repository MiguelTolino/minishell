/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 13:38:48 by mmateo-t          #+#    #+#             */
/*   Updated: 2022/02/18 20:07:18 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

//FIXME: Comprobar mejor que el numero es solo digitos y si no exity && laznar error
// Si le paso varios argumentos lanzar error
 
void	exit_cmd(char **cmd)
{	
	if(!cmd[1])
		exit(EXIT_SUCCESS);
	else
		exit(ft_atoi(cmd[1]));
}
