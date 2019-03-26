/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 16:48:32 by cpalmier          #+#    #+#             */
/*   Updated: 2019/03/26 19:01:57 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/wolf3d.h"

void	init_sprite(t_env *env)
{
	env->sp[0].img = mlx_xpm_file_to_image(env->mlx,
			"textures/8-grid.XPM", &env->sp[0].width, &env->sp[0].height);
	env->sp[0].img_str = mlx_get_data_addr(env->sp[0].img,
			&env->sp[0].bpp, &env->sp[0].s_l, &env->sp[0].end);
	env->sp[1].img = mlx_xpm_file_to_image(env->mlx,
			"textures/9-window.XPM", &env->sp[1].width, &env->sp[1].height);
	env->sp[1].img_str = mlx_get_data_addr(env->sp[1].img,
			&env->sp[1].bpp, &env->sp[1].s_l, &env->sp[1].end);
	env->sp[2].img = mlx_xpm_file_to_image(env->mlx,
			"textures/12-column.XPM", &env->sp[2].width, &env->sp[2].height);
	env->sp[2].img_str = mlx_get_data_addr(env->sp[2].img,
			&env->sp[2].bpp, &env->sp[2].s_l, &env->sp[2].end);
	env->sp[3].img = mlx_xpm_file_to_image(env->mlx,
			"textures/13-banana.XPM", &env->sp[3].width, &env->sp[3].height);
	env->sp[3].img_str = mlx_get_data_addr(env->sp[3].img,
			&env->sp[3].bpp, &env->sp[3].s_l, &env->sp[3].end);
	env->sp[4].img = mlx_xpm_file_to_image(env->mlx,
			"textures/14-monkey.XPM", &env->sp[4].width, &env->sp[4].height);
	env->sp[4].img_str = mlx_get_data_addr(env->sp[4].img,
			&env->sp[4].bpp, &env->sp[4].s_l, &env->sp[4].end);
	env->sp[5].img = mlx_xpm_file_to_image(env->mlx,
			"textures/4-5-6-van_gogh.XPM", &env->sp[5].width, &env->sp[5].height);
	env->sp[5].img_str = mlx_get_data_addr(env->sp[5].img,
			&env->sp[5].bpp, &env->sp[5].s_l, &env->sp[5].end);
	env->sp[6].img = mlx_xpm_file_to_image(env->mlx,
			"textures/gun.XPM", &env->sp[6].width, &env->sp[6].height);
	env->sp[6].img_str = mlx_get_data_addr(env->sp[6].img,
			&env->sp[6].bpp, &env->sp[6].s_l, &env->sp[6].end);
}
