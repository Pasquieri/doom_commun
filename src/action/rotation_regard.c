/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_regard.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpasquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 13:44:10 by mpasquie          #+#    #+#             */
/*   Updated: 2019/04/30 21:40:10 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/doom_nukem.h"

void	rotation_regard(t_env *env)
{
	if (env->key[78])
		env->d_regard += 1;
	else if (env->key[69])
		env->d_regard -= 1;
	if (env->key[123])
		env->d_regard += 5;
	else if (env->key[124])
		env->d_regard -= 5;
	else if (env->key[125] && env->h_regard > 0)
		env->h_regard -= 12;
	else if (env->key[126] && env->h_regard < 770)
		env->h_regard += 12;
	env->d_regard = env->d_regard % 360;
	if (env->d_regard < 0)
		env->d_regard = env->d_regard + 360;
}
