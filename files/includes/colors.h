/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 18:02:29 by mmateo-t          #+#    #+#             */
/*   Updated: 2022/02/23 18:58:46 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/* Colors
Black       0;30     Dark Gray     1;30
Blue        0;34     Light Blue    1;34
Green       0;32     Light Green   1;32
Cyan        0;36     Light Cyan    1;36
Red         0;31     Light Red     1;31
Purple      0;35     Light Purple  1;35
Brown       0;33     Yellow        1;33
Light Gray  0;37     White         1;37

	\033[47;31m string \033[0m
47->color de fondo
31->color del carácter
\033[5m es el código de control
*/

#ifndef COLORS_H
# define COLORS_H
#  define NC "\001\033[0m\002" //No Color
#  define BLACK "\001\033[0;30m\002"
#  define RED "\001\033[0;31m\002"
#  define GREEN "\001\033[0;32m\002"
#  define BROWN "\001\033[0;33m\002"
#  define BLUE "\001\033[0;34m\002"
#  define PURPLE "\001\033[0;35m\002"
#  define CYAN "\001\033[0;36m\002"
#  define COLOR(x,y) "\001\033["#x";"#y"m\002"

#endif
