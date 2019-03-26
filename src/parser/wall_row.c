/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_row.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpasquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 16:50:57 by mpasquie          #+#    #+#             */
/*   Updated: 2019/03/03 17:58:37 by mpasquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/wolf3d.h"

int		wall_row(char *str, int nb_char, t_env *env)
{
	if (str[0] == '0' && str[--nb_char] == '0')
		return (0);
	free(str);
	return (error_message(12, env));
}
