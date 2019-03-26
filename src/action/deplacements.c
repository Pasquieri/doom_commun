/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deplacements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 17:41:36 by cpalmier          #+#    #+#             */
/*   Updated: 2019/03/03 15:09:43 by mpasquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/wolf3d.h"

void	deplacements(t_env *env)
{
	if (env->key[1])
		depla_vertical(env, 1);
	if (env->key[13])
		depla_vertical(env, 13);
	if (env->key[0])
		depla_horizontal(env, 0);
	if (env->key[2])
		depla_horizontal(env, 2);
}
