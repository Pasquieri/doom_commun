/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion_notify.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpasquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 13:43:26 by mpasquie          #+#    #+#             */
/*   Updated: 2019/04/07 13:51:26 by mpasquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/wolf3d.h"

int		motion_notify(int x, int y, t_env *env)
{
	int	tmp_y;
	int	tmp_x;

	tmp_x = abs(x - 600);
	tmp_y = abs(y - 435);
	mouse_move(env);
	if (env->menu == 1)
		return (0);
	if (x > W_WIDTH || x < 0 || y > W_HEIGHT || y < 0)
		return (0);
	if (x > 600)
		env->d_regard -= (40 * tmp_x / 600);
	else if (x < 600)
		env->d_regard += (40 * tmp_x / 600);
	if (y < 435 && (env->h_regard < (W_HEIGHT / 2 + 200))) //+200
		env->h_regard += (100 * tmp_y / 435);
	else if (y > 435 && (env->h_regard > (W_HEIGHT / 2 - 200))) //-200
		env->h_regard -= (100 * tmp_y / 435);
	env->d_regard = env->d_regard % 360;
	if (env->d_regard < 0)
		env->d_regard = env->d_regard + 360;
	//exec_calcul(env, 0, 0);
	return (0);
}
