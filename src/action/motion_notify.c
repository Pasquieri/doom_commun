/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion_notify.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpasquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 13:43:26 by mpasquie          #+#    #+#             */
/*   Updated: 2019/03/26 16:08:21 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/wolf3d.h"

int		motion_notify(int x, int y, t_env *env)
{
	if (env->menu == 1)
		return (0);
	if (x > W_WIDTH || x < 0 || y > W_HEIGHT || y < 0)
		return (0);
	if (x > 650)
		env->d_regard -= 1;
	else if (x < 550)
		env->d_regard += 1;
	if (y < 250 && (env->h_regard < (W_HEIGHT / 2 + 200)))
		env->h_regard += 2;
	else if (y > 620 && (env->h_regard > (W_HEIGHT / 2 - 200)))
		env->h_regard -= 2;
	env->d_regard = env->d_regard % 360;
	if (env->d_regard < 0)
		env->d_regard = env->d_regard + 360;
	exec_calcul(env, 0, 0);
	return (0);
}
