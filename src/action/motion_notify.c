/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion_notify.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpasquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 13:43:26 by mpasquie          #+#    #+#             */
/*   Updated: 2019/04/10 00:15:40 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/wolf3d.h"

int		motion_notify(int x, int y, t_env *env)
{
	int	tmp_y;
	int	tmp_x;

	tmp_x = abs(x - W_WIDTH / 2);
	tmp_y = abs(y - W_HEIGHT / 2);
	mouse_move(env);
	if (env->menu == 1)
		return (0);
	if (x > (W_WIDTH / 2))
		env->d_regard -= (40 * tmp_x / (W_WIDTH / 2));
	else if (x < (W_WIDTH / 2))
		env->d_regard += (40 * tmp_x / (W_WIDTH / 2));
	env->d_regard = env->d_regard % 360;
	if (env->d_regard < 0)
		env->d_regard = env->d_regard + 360;
	if (y < (W_HEIGHT / 2) && ((env->h_regard + (100 * tmp_y / 435)) < 800))
		env->h_regard += (100 * tmp_y / (W_HEIGHT / 2));
	else if (y > (W_HEIGHT / 2) && ((env->h_regard - 100 * tmp_y / 435) > 70))
		env->h_regard -= (100 * tmp_y / (W_HEIGHT / 2));
	return (0);
}
